/*
 * GetHistory.h
 *
 *  Created on: 3 Sep 2018
 *      Author: roberty
 */

#ifndef GETHISTORY_H_
#define GETHISTORY_H_
#include <string>
#include <iostream>
#include "device.h"
#include "GetOS.h"
#include <stdio.h>
#include <stdlib.h>

#include "GetRemoteConfig.h"
#include <set>
class GetHistory {

public:
	GetHistory();
	virtual ~GetHistory();
	static map<string,Device> getInstalledDevices();

};

#endif /* GETHISTORY_H_ */
