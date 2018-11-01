/*
 * GetOS.h
 *
 *  Created on: 2 Sep 2018
 *      Author: roberty
 */

#ifndef GETOS_H_
#define GETOS_H_

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
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

class GetOS {
public:
	static std::string exec(const char* cmd);
	static std::string* getLocalMchineDistro();
	static bool is_gui_present();
    static int attempt_number;
	GetOS();
    virtual ~GetOS();
    static void runWebpage(string url);
    static void runEmail(string email);
    static string DoRestore(string restorefile);
    static void reset_reboot();
    static void eraseFileLine(std::string path, std::string eraseLine);
    static string get_pk_user(string uid);


};

#endif /* GETOS_H_ */
