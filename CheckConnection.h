/*
 * CheckConnection.h
 *
 *  Created on: 25 Aug 2018
 *      Author: roberty
 */

#ifndef CHECKCONNECTION_H_
#define CHECKCONNECTION_H_


#include <iostream>
#include <sstream>
#include <ostream>
#include <fstream>
#include <curlpp/cURLpp.hpp>

class CheckConnection {

public:
    /// checks a network connection by downloading from google.
	static bool CheckNetwork();


};




#endif /* CHECKCONNECTION_H_ */
