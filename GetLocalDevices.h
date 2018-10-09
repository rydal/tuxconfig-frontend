/*
 * getdevices.h
 *
 *  Created on: 20 Aug 2018
 *      Author: roberty
 */

#ifndef GETLOCALDEVICES_H_
#define GETLOCALDEVICES_H_
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <sstream>
#include <regex>
#include <map>
#include <set>
#include <set>
#include "compare.h"
#include <boost/algorithm/string.hpp>
#include "device.h"
#include <fstream>
#include <streambuf>
#include "GetOS.h"


class GetLocalDevices {
public:
	GetLocalDevices();
	virtual ~GetLocalDevices();
	static std::string exec(const char* cmd);
	static std::set<Device> listdevices();
	static Device listdevice(string device);
	std::set<Device> data;
};




#endif /* GETLOCALDEVICES_H_ */
