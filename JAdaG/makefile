all:
#	g++ -o build/simpleExif -I/usr/local/include -L/usr/local/lib -lexiv2 simpleexif.cpp
#	g++ -o build/simpleDate -I/usr/local/include -L/usr/local/lib -lexiv2 simpleDateChanger.cpp
#	g++ -o build/simpleGPS -I/usr/local/include -L/usr/local/lib -lexiv2 simpleGPSadder.cpp
#	g++ -o build/simpleXML simpleXMLParser.cpp xmlParser/xmlParser.cpp -I/usr/local/include -L/usr/local/lib -lexiv2
#	g++ -o build/simpleGPX simpleGPXParser.cpp xmlParser/xmlParser.cpp -I/usr/local/include -L/usr/local/lib -lexiv2
	g++ -o build/JAdaG jadag.cpp xmlParser/xmlParser.cpp util.cpp gps.cpp -I/usr/local/include -L/usr/local/lib -lexiv2

clean:
	rm -rf build/
	mkdir build

run:
	./build/JAdaG ../input/pictures/ ../input/gpx/

run2:
	./build/JAdaG ../input/pictures/
