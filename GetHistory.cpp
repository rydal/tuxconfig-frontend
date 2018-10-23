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
    std::ifstream input_file("/var/lib/tuxconfig/history");
      std::ofstream output_file("/var/lib/tuxconfig/revsrsed_history");
      std::istreambuf_iterator<char> input_begin(input_file);
      std::istreambuf_iterator<char> input_end;
      std::ostreambuf_iterator<char> output_begin(output_file);
      std::vector<char> input_data(input_begin, input_end);

      std::reverse_copy(input_data.begin(), input_data.end(), output_begin);

       ifstream inputFile("/var/lib/tuxconfig/revsrsed_history");
      string tempLine;
    while (getline(inputFile, tempLine, '\n')) {
        vector<string> tempstr;
        stringstream ss(tempLine);
        string temp;

        while (getline(ss, temp, ',')) {
            tempstr.push_back(temp);

}
		Device new_device;

        if (tempstr[5].find("works") != string::npos) {
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
        if (tempstr[5].find("failed") != string::npos
                ) {
            boost::trim(tempstr[0]);
            boost::trim(tempstr[1]);
            new_device = Device(tempstr[0], tempstr[1], false, false);
            std::map<string,Device>::iterator it = device_map.find(tempstr[0]);
            if (it != device_map.end())
                it->second = new_device;
            else {
            device_map.insert(
                    std::pair<string, Device>(tempstr[0], new_device));
            }


        if (tempstr[5].find("module-installed") != string::npos
                ) {
			boost::trim(tempstr[0]);
			boost::trim(tempstr[1]);
            new_device = Device(tempstr[0], tempstr[1], false, true);
            std::map<string,Device>::iterator it = device_map.find(tempstr[0]);

            if (it != device_map.end())
                it->second = new_device;
            else {
            device_map.insert(
                    std::pair<string, Device>(tempstr[0], new_device));
            }

        }
        }
            if (tempstr[5].find("apt-installed") != string::npos
                    ) {
                boost::trim(tempstr[0]);
                boost::trim(tempstr[1]);
                new_device = Device(tempstr[0], tempstr[1], false, true);
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

