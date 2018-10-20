/*
 * RestoreGUI.cpp
 *
 *  Created on: 16 Sep 2018
 *      Author: roberty
 */

#include "RestoreCmd.h"


string restore_command;
Device restore_device;
using namespace std;
RestoreGUI::RestoreGUI(std::map<std::string,Device> hashmap) {

}
void RestoreGUI::on_button_clicked(std::string command,Device device) {
	string found_files = "find /var/lib/tuxconfig/ -name \"lib_backup-" + device.getDeviceid() + "*.tar\" -printf \"%T@  %p\n\" | sort -n | head -1 | sed 's/^ *//'| cut -d\" \" -f2- ";
		string restore_file = GetOS::exec(found_files.c_str());

		DoRestore(restore_file);


}

RestoreGUI::~RestoreGUI() {
	// TODO Auto-generated destructor stub
}

bool RestoreGUI::CommandLineInstall(std::map <string,Device> device_map) {
	string result;
	string response;
	cout<<"Don't panic \n";
	cout<<"Everything configured ok? \n";
	string answer;
	getline (cin,answer);
	boost::to_lower(answer);
	if (answer == "y" || answer == "yes") {
		cout<<"good :) \n";
				exit(0);
	}

		cout<<"Devices installed: \n";
		std::map<string, Device>::iterator it;
		cout<<"Device id:\t"<<"Device description \n";

	do {
	for ( it = device_map.begin(); it != device_map.end(); it++ )
	{
		string installed_status;
		if (it->second.getAttemptedInstall()) {
			installed_status = "Failed install";

		} else  if (it->second.isIsInstalled()){
			installed_status = "Successful install";
		}

	    std::cout << it->first
	              << ":"
	              << it->second.getDescription()   // string's value
				  << "\t" + installed_status
	              << std::endl ;
	}
	cout<<"Enter the device id you wish to restore:";
	 getline(cin, response);


	boost::trim(response);

	} while  (device_map.find(response) == device_map.end() );

	string found_files = "find /var/lib/tuxconfig/ -name \"lib_backup-" + response + "*.tar\" -printf \"%T@  %p\n\" | sort -n | head -1 | sed 's/^ *//'| cut -d\" \" -f2- ";
	string restore_file = GetOS::exec(found_files.c_str());



	return DoRestore(restore_file);

}
bool RestoreGUI::DoRestore(string restorefile) {
	string runfile = "";
	runfile += "#! /bin/bash \n";
    runfile += "tar -C / -xvf /var/lib/tuxconfig/backup/" + restorefile;
	string restore_run_file = "/usr/src/tuxconfig-restore";
		std::ofstream out(restore_run_file);
		out << runfile;
		out.close();
        return true;
	}




