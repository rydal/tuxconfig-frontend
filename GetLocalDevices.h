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
#include <curl/curl.h>


class GetLocalDevices {
public:
    /** Constructor
     * @brief GetLocalDevices
     */
	GetLocalDevices();
    /** Destructor
     */
	virtual ~GetLocalDevices();
    /** Returns a list of all devices found using lshw -numeric
     * @brief listdevices
     * @return
     */
	static std::set<Device> listdevices();
    std::set<Device> data;
};




#endif /* GETLOCALDEVICES_H_ */
