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
#include <fstream>
#include "device.h"
#include "GetOS.h"
#include <stdio.h>
#include <stdlib.h>

#include "GetRemoteConfig.h"

#include <set>
#include <sys/time.h>
#include <sys/wait.h>
#include <regex>
#include <sys/stat.h>

using namespace std;
class RunConfig {
public:
    /** Default constructor
     * @brief RunConfig
     */
	RunConfig();
    /** Deconstructor.
     * @brief ~RunConfig
     */
	virtual ~RunConfig();
    /** writes instal bash script in /usr/src/
     * @brief install
     * @param m_device
     * @return  vector of { install sctipr, test program, test messsage, reboot flag }
     */
    static vector<string> install( Device& m_device) ;
    /** Creates uninstall bash file.
     * @brief uninstall
     * @param m_device
     * @return  vector containing uninstall script name.
     */
    static vector<string> uninstall( Device& m_device);
    /** creates install script.
     * @brief upgrade
     * @param m_device
     * @return install method called with new device.
     */
    static vector<string> upgrade( Device& m_device);
    /**
     * @brief restore
     * @param m_device
     * @return  vector containing restore script name.
     */
    static vector<string> restore(Device& m_device);



};

#endif /* RUNCONFIG_H_ */
