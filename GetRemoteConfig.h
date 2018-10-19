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
#include <curlpp/Options.hpp>
#include <jsoncpp/json/json.h>
#include "device.h"
#include "GetOS.h"

class GetRemoteConfig {

public:
	GetRemoteConfig();
	~GetRemoteConfig();

	//std::string data;
	size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up);
	 static Device GetConfiguration(Device configured_device);
	 static bool isUpgradeable(Device current_device);
     static int attempt_number;


};



#endif /* GETREMOTECONFIG_H_ */
