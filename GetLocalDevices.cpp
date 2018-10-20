#include "GetLocalDevices.h"

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <sstream>
#include <regex>
#include <map>
#include <set>

#include "device.h"


using namespace std;

GetLocalDevices::GetLocalDevices() {};
GetLocalDevices::~GetLocalDevices() {};






set<Device> GetLocalDevices::listdevices() {

	std::string output = GetOS::exec("lshw -numeric");
	std::stringstream iss(output);
	set<Device> data;

	string deviceid = "";
	string name = "";
	string modulename = "";
	string description = "";
    bool new_device = false;
	while (iss.good()) {

		std::string SingleLine;
		getline(iss, SingleLine, '\n');

		std::smatch m4;
		std::regex e4("^\\s*description.*");
		if (regex_search(SingleLine, m4, e4)) {
			description = m4[0];
		description = std::regex_replace(description,regex("^\\s*description:\\s*"),"");
		boost::trim(description);
		if (description == "") { description = "null"; }

		}



		std::smatch m;
		std::regex e("^\\s*product.*\\[(.*?)\\]");



		if (regex_search(SingleLine, m, e)) {
			name = m[0];
			std::regex pattern1("product:\\s*");
			std::regex pattern2("\\[.*\\]");

			name = std::regex_replace(name,pattern1,"");
			name = std::regex_replace(name,pattern2,"");
			deviceid = m[1];
			boost::trim(deviceid);
			boost::trim(name);

		}
        std::smatch m1;

        std::regex e1("^\\s*configuration:.*");
        std::regex e2("^\\s*configuration:.*driver=(.*)(.*)");

        if (regex_match(SingleLine, m1, e1)) {
                        modulename = "null";
            if  	(regex_search(SingleLine, m1, e2)) {
                modulename = m1[1];
                            std::regex pattern("\\s.*$");
                modulename = std::regex_replace(modulename, pattern, "");

        }

        }
        std::regex e5("^[\\s|\\t].*\\*-.*");
        std::smatch m5;
        if (regex_match(SingleLine,m5,e5)) {
            if(  ( modulename != "" || modulename == "null")   &&  ( description != "" || description != "null") && name != "" && deviceid != ""   ) {
                //don't list virtual devices
            Device object(deviceid,description,name,modulename);

            data.insert(object);
            deviceid = "";
            description = "";
            name = "";
            modulename = "";

        }

    }



    }
	return data;
}
