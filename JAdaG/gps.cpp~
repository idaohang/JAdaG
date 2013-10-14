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

#include "gps.h"

gps::gps()
{
}

gps::gps(double longitude, double latitude, double altitude,
    unsigned long long timestamp)
{
    mlongitude = longitude;
    mlatitude  = latitude;
    maltitude  = altitude;
    mtimeStamp = timestamp;
}

const double& gps::latitude(void)
{
    return mlatitude;
}

void gps::setlatitude(const double& latitude)
{
    mlatitude = latitude;
}

const double& gps::longitude(void)
{
    return mlongitude;
}

void gps::setlongitude(const double& longitude)
{
    mlongitude = longitude;
}

const double& gps::altitude(void)
{
    return maltitude;
}

void gps::setaltitude(const double& altitude)
{
    maltitude = altitude;
}

const unsigned long long& gps::timestamp(void)
{
    return mtimeStamp;
}

void gps::settimestamp(const unsigned long long& timestamp)
{
    mtimeStamp = timestamp;
}
