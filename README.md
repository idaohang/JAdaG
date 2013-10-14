# JAdaG

A small cmd-line tool that adds GPS-Data to your images.


# Description

This little tool is made to make people happy who do not have a Camera with GPS-Support but a GPS-Logger which produces .gpx files. Based on the timestamp an image gets the GPS-Data with the smallest time shift between GPS-Data and image capturing time. 
You can use this Software to remove GPS-Data, too. Just leave the second Argument blank and tell with the first param the path to an image-directory.

If you have ideas, constructive criticism or want to contribute to the project, please feel free to contact the author at anytime. Using this project or parts of it in derived works is highly encouraged. Please respect the licensing and mention the author "Markus Solbach solbach.m@gmail.com".


# Build instructions

The tool has been successfully tested on Ubuntu 12.04. For sake of simplicity, all required externals except exiv2 are included. I have used exiv2 v0.23 for testing.

## Linux
- Install exiv2 Library
- make all
- make run

# License

This tool is licensed under the [GNU General Public License](http://www.gnu.org/licenses/gpl-3.0.en.html, "GPLv3").
