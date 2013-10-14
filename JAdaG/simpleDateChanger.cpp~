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
* @brief Changes the Date/Time of a given Picture to "00.00.0000 00:00:00"
*
*/

#include <exiv2/exiv2.hpp>
#include <iostream>
#include <iomanip>
#include <cassert>

int main(int argc, char* const argv[])
try {

    std::cout << "SimpleDate" << std::endl;

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

    Exiv2::Exifdatum& tag = exifData["Exif.Photo.DateTimeOriginal"];
    std::string date = tag.toString();

    date.replace(0, 19, "0000:00:00 00:00:00");

    tag.setValue(date);

    std::cout << "Modified key \"" << "\", new value \""
              << tag.value() << "\"\n";


    // Write Informationen to Image
    image->setExifData(exifData);
    image->writeMetadata();


    return 0;
}
catch (Exiv2::AnyError& e) {
    std::cout << "Caught Exiv2 exception '" << e.what() << "'\n";
    return -1;
}
