/*
 * Feedback.h
 *
 *  Created on: 9 Sep 2018
 *      Author: roberty
 */

#ifndef FEEDBACK_H_
#define FEEDBACK_H_
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>
#include <jsoncpp/json/json.h>
#include "device.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

using namespace std;

class Feedback {
public:
    Feedback(Device device, bool successful);
	virtual ~Feedback();
	static  bool ReturnVoteStatus();

};

#endif /* FEEDBACK_H_ */
