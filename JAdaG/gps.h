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

#ifndef GPS_H
#define GPS_H

#include <iostream>

class gps
{

public:
    gps();
    gps(double longitude, double latitude, double altitude,
        unsigned long long timestamp);

    const double& latitude(void);
    void setlatitude(const double& latitude);

    const double& longitude(void);
    void setlongitude(const double& longitude);

    const double& altitude(void);
    void setaltitude(const double& altitude);

    const unsigned long long& timestamp(void);
    void settimestamp(const unsigned long long& timestamp);

private:
    double mlatitude;
    double mlongitude;
    double maltitude;
    unsigned long long mtimeStamp;
};

#endif // GPS_H
