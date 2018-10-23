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
RestoreGUI::~RestoreGUI() {
	// TODO Auto-generated destructor stub
}

bool RestoreGUI::CommandLineInstall(std::map <string,Device> device_map) {
    string response;
    bool apt_installed;
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
        apt_installed = false;
		string installed_status;
		if (it->second.getAttemptedInstall()) {
			installed_status = "Failed install";

		} else  if (it->second.isIsInstalled()){
			installed_status = "Successful install";
		}
        if (it->second.getAptInstalled()) {
            apt_installed = true;
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

        string found_files = "find /var/lib/tuxconfig/ -name \"" + response + "*.tar\" -printf \"%T@  %p\n\" | sort -n | head -1 | sed 's/^ *//'| cut -d\" \" -f2- ";
        string restorefile = GetOS::exec(found_files.c_str());
 string runfile = "";
runfile += "#! /bin/bash \n";
runfile += "set -e \n";

runfile += "exec > >(tee -i /var/lib/tuxconfig/" + response + ".log) \n";
runfile += "function cleanup() { \n";
runfile += "kill -SIGUSR2 " + to_string(::getpid()) + " \n";
runfile += "} \n";
runfile += "tar -C / -xvf /var/lib/tuxconfig/" +  restorefile + "\n";
if (apt_installed) {
    runfile +="$ apt-get -s install $(apt-history rollback | tr '\n' ' ') \n";
}

string restore_run_file = "/usr/src/tuxconfig-" + response + "-restore";

    std::ofstream out(restore_run_file);
    out << runfile;
    out.close();
    chmod(runfile.c_str(), S_IRWXU);



    int result = system(runfile.c_str());
    if (result == 0) {
        cout<<"Configuration restored successfully"<<endl;
    } else {
        cout<<"Configuration restore failed"<<endl;
    }
    cout<<"Restart?"<<endl;
    string choose_reboot;
    getline (cin,choose_reboot);
    boost::to_lower(choose_reboot);
    if (choose_reboot == "y" || choose_reboot == "yes") {
        sync();
        reboot(RB_AUTOBOOT);
    }



}