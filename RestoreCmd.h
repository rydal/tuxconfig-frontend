/*
 * RestoreGUI.h
 *
 *  Created on: 16 Sep 2018
 *      Author: roberty
 */

#ifndef RESTOREGUI_H_
#define RESTOREGUI_H_



#include <string>
#include <iostream>
#include "device.h"
#include "GetOS.h"
#include <stdio.h>
#include <stdlib.h>
#include "GetRemoteConfig.h"
#include <set>
#include <map>
#include "GetHistory.h"
#include <iterator>
#include <regex>
#include <boost/regex.h>
#include <boost/filesystem/path.hpp>
#include <fstream>
#include <iostream>
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/reboot.h>
#include <sys/stat.h>


using namespace std;


class RestoreGUI  {
public:
	RestoreGUI(std::map<std::string,Device> hashmap);
	virtual ~RestoreGUI();
    static bool CommandLineInstall(std::map <string,Device> device_map);
    static string DoRestore(string restorefile);


protected:

	   std::set<Device> data;
	   void on_button_clicked(std::string command,Device device);


};

#endif /* RESTOREGUI_H_ */
