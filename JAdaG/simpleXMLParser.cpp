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
* @brief Play around with xmlParser
*
*/

#include "xmlParser/xmlParser.h"

#include <stdio.h>    // to get "printf" function
#include <stdlib.h>   // to get "free" function

int main(int argc, char **argv)
{
  // this open and parse the XML file:
  XMLNode xMainNode=XMLNode::openFileHelper(argv[1],"PMML");

  // this prints "<Condor>":
  XMLNode xNode=xMainNode.getChildNode("Header");
  printf("Application Name is: '%s'\n", xNode.getChildNode("Application").getAttribute("name"));

  // this prints "Hello world!":
  printf("Text inside Header tag is :'%s'\n", xNode.getText());

  // this gets the number of "NumericPredictor" tags:
  xNode=xMainNode.getChildNode("RegressionModel").getChildNode("RegressionTable");
  int n=xNode.nChildNode("NumericPredictor");

  // this prints the "coefficient" value for all the "NumericPredictor" tags:
  for (int i=0; i<n; i++)
    printf("coeff %i=%f\n",i+1,atof(xNode.getChildNode("NumericPredictor",i).getAttribute("coefficient")));

  // this prints a formatted ouput based on the content of the first "Extension" tag of the XML file:
  char *t=xMainNode.getChildNode("Extension").createXMLString(true);
  printf("%s\n",t);
  free(t);
  return 0;
}
