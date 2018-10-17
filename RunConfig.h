/*#include "config.h"
 *
 * RunConfig.h
 *
 *  Created on: 3 Sep 2018
 *      Author: roberty
 */

#ifndef RUNCONFIG_H_
#define RUNCONFIG_H_
#include <string>
#include <iostream>
#include "device.h"
#include "GetOS.h"
#include <stdio.h>
#include <stdlib.h>

#include "GetRemoteConfig.h"

#include <set>
#include <sys/time.h>
#include <sys/wait.h>
#include <regex>

using namespace std;
class RunConfig {
public:
	std::string exec(const char* cmd);

	RunConfig();

	virtual ~RunConfig();
    static vector<string> install( Device m_device) ;
    static vector<string> uninstall( Device m_device);
    static vector<string> upgrade( Device m_device);
    static vector<string> restoreGUI(Device m_device);
    static bool restoreCmd(Device m_device);



};

#endif /* RUNCONFIG_H_ */
