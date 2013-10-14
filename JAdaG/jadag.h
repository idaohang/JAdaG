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

#ifndef JADAG_H
#define JADAG_H

#include "gps.h"
#include "util.h"
#include "xmlParser/xmlParser.h"

#include <exiv2/exiv2.hpp>
#include <iostream>
#include <stdlib.h>   // to convert string to unsigned long long
#include <dirent.h>   // read directories (without boost)


class JAdaG
{

public:
    JAdaG(std::string imgDir, std::string gpxDir);
    JAdaG(std::string imgDir);
    ~JAdaG(void);

    void parseGPX(void);
    void apply(void);
    void applyRemoval(void);

private:
    std::string mImgDir;
    std::string mGpxDir;
    std::vector<gps*> mGps;
    unsigned long long mAvDistance;

};

#endif // JADAG_H
