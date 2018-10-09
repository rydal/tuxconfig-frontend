/*
 * compare.h
 *
 *  Created on: 25 Aug 2018
 *      Author: roberty
 */

#ifndef COMPARE_H_
#define COMPARE_H_
#include "device.h"
class compare {
public:
		bool operator() (Device lhs, Device rhs);
		bool operator() (const Device lhs, const  Device rhs) const;
		bool operator< (Device& lhs);
		bool operator< (const Device& lhs) const;

	};



#endif /* COMPARE_H_ */

