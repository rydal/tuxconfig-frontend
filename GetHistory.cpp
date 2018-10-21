/*
 * GetHistory.cpp
 *
 *  Created on: 3 Sep 2018
 *      Author: roberty
 */

#include "GetHistory.h"
using namespace std;
GetHistory::GetHistory() {
	// TODO Auto-generated constructor stub
	//get history details
	string line;
	ifstream inFile;

}

GetHistory::~GetHistory() {
	// TODO Auto-generated destructor stub
}
map<string, Device> GetHistory::getInstalledDevices() {
	std::map<string, Device> device_map;
   ifstream inputFile("/var/lib/tuxconfig/history");
    string tempLine;
    while (getline(inputFile, tempLine, '\n')) {
        vector<string> tempstr;
        stringstream ss(tempLine);
        string temp;

        while (getline(ss, temp, ',')) {
            tempstr.push_back(temp);
            cout<<"pushing back:"<<temp<<endl;
}
		Device new_device;


        if (tempstr[5].find("module-installed") != string::npos
                ) {
			boost::trim(tempstr[0]);
			boost::trim(tempstr[1]);
			new_device = Device(tempstr[0], tempstr[1], true, false);
			device_map.insert(
					std::pair<string, Device>(tempstr[0], new_device));

		}
        if (tempstr[5].find("uninstalled") != string::npos
                ) {
			boost::trim(tempstr[0]);
			boost::trim(tempstr[1]);
			new_device = Device(tempstr[0], tempstr[1], true, false);
			std::map<string,Device>::iterator it = device_map.find(tempstr[0]);
			if (it != device_map.end())
                it->second = new_device;
			else {
			device_map.insert(
					std::pair<string, Device>(tempstr[0], new_device));
			}

        }
            if (tempstr[5].find("apt-installed") != string::npos
                    ) {
                boost::trim(tempstr[0]);
                boost::trim(tempstr[1]);
                new_device = Device(tempstr[0], tempstr[1], true, false);
                new_device.setAptInstalled(true);
                std::map<string,Device>::iterator it = device_map.find(tempstr[0]);
                if (it != device_map.end())
                    it->second = new_device;
                else {
                device_map.insert(
                        std::pair<string, Device>(tempstr[0], new_device));
                }

            }

    }

	return device_map;
}

