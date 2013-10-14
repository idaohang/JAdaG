/***********************************************************************
*
* JAdaG helper
*
* This cmd-line Tool attaches GPS-Data to your images using timestamps
* Copyright (C) 2013 Markus Solbach <solbach.m@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
***********************************************************************/

/**
* @class main
*
* @author Markus Solbach
*
* @brief Add a GPS-Stamp to a given Image
*
*/

#include <exiv2/exiv2.hpp>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cassert>
#include <cmath>


typedef struct
{
    double latitude;
    double longitude;
    double altitude;
    std::string timeStamp;
}GPS;

int main(int argc, char* const argv[])
try {

    std::cout << "SimpleGPS" << std::endl;

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " file\n";
        return 1;
    }

    std::string file(argv[1]);
    Exiv2::ExifData exifData;

    // Load Image
    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(file);
    assert(image.get() != 0);

    // Read Exif Data
    image->readMetadata();
    exifData = image->exifData();

    // For testing
    GPS gpsDate;
    gpsDate.latitude = 47.38076;
    gpsDate.longitude = 11.287598;
    gpsDate.altitude = 1021;

    // Umrechnungen in Winkelminuten
    char tmp[50];

    // Altitude
    snprintf(tmp, 50, "%d/10", (int)(gpsDate.altitude * 10));
    exifData["Exif.GPSInfo.GPSAltitude"] = std::string(tmp);
    exifData["Exif.GPSInfo.GPSAltitudeRef"] = (gpsDate.altitude < 0) ? "1" :"0";

    double absVal, remai;
    int deg, min, sec;

    // Latitude
    absVal = fabs(gpsDate.latitude);
    deg = (int)absVal;

    remai = absVal - deg;
    min = floor(remai * 60);

    remai = (remai * 60) - min;
    sec = (remai * 60 * 100000);

    snprintf(tmp, 50, "%d/1 %d/1 %d/100000", deg, min, sec);
    std::cout << "\n\t Latitude: " << tmp << "\n";

    exifData["Exif.GPSInfo.GPSLatitude"] = std::string(tmp);
    exifData["Exif.GPSInfo.GPSLatitudeRef"] = (gpsDate.latitude < 0) ? "S" :"N";

    // Longitude
    absVal = fabs(gpsDate.longitude);
    deg = (int)absVal;

    remai = absVal - deg;
    min = floor(remai * 60);

    remai = (remai * 60) - min;
    sec = (remai * 60 * 100000);

    snprintf(tmp, 50, "%d/1 %d/1 %d/100000", deg, min, sec);
    std::cout << "\n\t Longitude: " << tmp << "\n";

    exifData["Exif.GPSInfo.GPSLongitude"] = std::string(tmp);
    exifData["Exif.GPSInfo.GPSLongitudeRef"] = (gpsDate.longitude <0) ? "W":"E";

    // Write Informationen to Image
    image->setExifData(exifData);
    image->writeMetadata();


    return 0;
}
catch (Exiv2::AnyError& e) {
    std::cout << "Caught Exiv2 exception '" << e.what() << "'\n";
    return -1;
}
