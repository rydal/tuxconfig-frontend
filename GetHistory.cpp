/*
 * GetHistory.cpp
 *
 *  Created on: 3 Sep 2018
 *      Author: roberty
 */

#include "GetHistory.h"
using namespace std;
GetHistory::GetHistory() {

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

}
		Device new_device;

        if (tempstr[6].find("works") != string::npos) {
            boost::trim(tempstr[0]);
            boost::trim(tempstr[1]);
            new_device = Device(tempstr[0], tempstr[1], true, false, tempstr[4],tempstr[6], tempstr[5]);
            new_device.setDescription(tempstr[5]);
            std::map<string,Device>::iterator it = device_map.find(tempstr[0]);

            if (it != device_map.end())
                it->second = new_device;
            else {
            device_map.insert(
                    std::pair<string, Device>(tempstr[0], new_device));
            }
            cout<<"added"<<endl;

        }
        else if (tempstr[6].find("failed") != string::npos
                ) {
            boost::trim(tempstr[0]);
            boost::trim(tempstr[1]);
            new_device = Device(tempstr[0], tempstr[1], false, false, tempstr[4],tempstr[6], tempstr[5]);
            std::map<string,Device>::iterator it = device_map.find(tempstr[0]);
            if (it != device_map.end())
                it->second = new_device;
            else {
            device_map.insert(
                    std::pair<string, Device>(tempstr[0], new_device));
            }
        }


        else if (tempstr[6].find("module-installed") != string::npos
                ) {
			boost::trim(tempstr[0]);
			boost::trim(tempstr[1]);
            new_device = Device(tempstr[0], tempstr[1], false, true, tempstr[4],tempstr[6], tempstr[5]);
            std::map<string,Device>::iterator it = device_map.find(tempstr[0]);

            if (it != device_map.end())
                it->second = new_device;
            else {
            device_map.insert(
                    std::pair<string, Device>(tempstr[0], new_device));
            }

        }

            else if (tempstr[6].find("apt-installed") != string::npos
                    ) {
                boost::trim(tempstr[0]);
                boost::trim(tempstr[1]);
                new_device = Device(tempstr[0], tempstr[1], false, true, tempstr[4],tempstr[6], tempstr[5]);
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

