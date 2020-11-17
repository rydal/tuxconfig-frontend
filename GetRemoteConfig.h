/*
 * GetConfig.h
 *
 *  Created on: 25 Aug 2018
 *      Author: roberty
 */
#ifndef GETREMOTECONFIG_H_
#define GETREMOTECONFIG_H_

#include <string>

#include <iostream>
#include <fstream>
#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <jsoncpp/json/json.h>

#include "device.h"
#include "GetOS.h"
#include <QtWidgets>
#include "QuestionBox.h"

#include <curlpp/Infos.hpp>
class GetRemoteConfig {
public:
    /** Constructor
     */
	GetRemoteConfig();
    /** Destructor
*/
~GetRemoteConfig();

	//std::string data;
    /** Returns a device with properties of the remote server, if exists in database and
     * has been verified as not malicious.
      * @brief GetConfiguration
      * @param configured_device
      * @return url, success_code, vote_difference, commit_hash, owner_git_id and module_name set
      */
     static Device GetConfiguration(Device& configured_device, bool restore_tab_asking);

};



#endif /* GETREMOTECONFIG_H_ */
