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
* @brief Simple GPX Parser (will parse for <trkpt>)
*
*/

#include "xmlParser/xmlParser.h"

#include <stdio.h>    // to get "printf" function
#include <iostream>
#include <stdlib.h>   // to convert string to unsigned long long

// Base is needed to convert from string to ulong long properly
#define BASE 10

unsigned long long dateString2ullong(std::string& date)
{
    // remove all unnecessary characters
    date.erase(4,1);
    date.erase(6,1);
    date.erase(8,1);
    date.erase(10,1);
    date.erase(12,1);

    // check whether the string is that long first
    if(date.size() > 14)
    {
    date.erase(14, date.size() - 14);
    }

    // convert String to char
    char* sChar, *stopstring;
    sChar = const_cast<char*>(date.c_str());

    // convert to ulong long and return
    return strtoul(sChar, &stopstring, BASE);
}

int main(int argc, char **argv)
{
  // this open and parse the XML file:
  XMLNode xMainNode=XMLNode::openFileHelper(argv[1],"gpx");

  // go to trk tag -> this where all the information is
  XMLNode trkNode = xMainNode.getChildNode("trk");

  // get number of trkseg tags to iterate over them
  int nTrkSeg = trkNode.nChildNode("trkseg");
  printf("I have found %i 'trkseg' - tags. \n", nTrkSeg);

  int count = 1;
  unsigned long long numTime;
  // iterate over all found trkseg tags
  for (int i=0; i<nTrkSeg; i++)
  {
      // get number of trkpt to iterate over them
      int nTrkpt = trkNode.getChildNode("trkseg",i).nChildNode("trkpt");

      for (int j=0; j<nTrkpt; j++)
      {
          printf("%i. Latitude: %f \t", count, atof(trkNode.getChildNode("trkseg",i).
                                        getChildNode("trkpt", j).
                                        getAttribute("lat")) );
          printf("Longitude: %f \t", atof(trkNode.getChildNode("trkseg",i).
                                        getChildNode("trkpt", j).
                                        getAttribute("lon")) );
          printf("Altitude: %f \t", atof(trkNode.getChildNode("trkseg",i).
                                        getChildNode("trkpt", j).
                                        getChildNode("ele").getText()) );

          std::string time( trkNode.getChildNode("trkseg",i).
                       getChildNode("trkpt", j).
                       getChildNode("time").getText() );

          numTime = dateString2ullong(time);

          std::cout << "NTime: " << numTime << "\n" << std::endl;

          count++;
      }
  }

  return 0;
}
