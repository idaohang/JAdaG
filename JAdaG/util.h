/***********************************************************************
*
* JAdaG
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

#ifndef UTIL_H
#define UTIL_H
// Base is needed to convert from string to ulong long properly
#define BASE 10

#include <stdlib.h>   // to convert string to unsigned long long
#include "gps.h"

#include <stdio.h>    // to get "printf" function
#include <iostream>
#include <exiv2/exiv2.hpp>
#include <cmath>      // math fun (floor, fabs, ...)

namespace jdg
{

    unsigned long long dateString2ullong(const std::string& timeVal);

    bool checkImgFileName (const std::string &file);

    bool checkGpxFileName (const std::string &file);

    unsigned long long euclDistance(const unsigned long long& val1,
                                    const unsigned long long& val2 );

    void writeGpsToExif(gps* bestGPS, Exiv2::ExifData& exifData);

    void deleteGpsFromExif(Exiv2::ExifData& exifData);

}

#endif // UTIL_H
