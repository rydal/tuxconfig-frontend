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
    /** function to execute a command and reutrn it's result
     */
	static std::string exec(const char* cmd);
    /** Returns an array of distribution details.
     * @brief getLocalMchineDistro
     * @return array {name, linux_version, architecture, kernel_version }
     */
	static std::string* getLocalMchineDistro();
    /** Returns true if gui is running.
     * @brief is_gui_present
     * @return
     */
	static bool is_gui_present();
    static int attempt_number;
    /** Constructor
     * @brief GetOS
     */
    GetOS();
    /** Destructor.
     * @brief ~GetOS
     */
    virtual ~GetOS();
    /** Derives calling user using $SUDO_USER then opens link using x-www-browser
     * @brief runWebpage
     * @param url
     */
    static void runWebpage(string url);
    /** Derives calling user using $SUDO_USER then opens email client to address.
     * @brief runEmail
     * @param email
     */
    static void runEmail(string email);
    /** Removes run on reboot as a file in .bashrc and in ~/.config/autostart/tuxconfig.desktop
     * @brief reset_reboot
     */
    static void reset_reboot();


};

#endif /* GETOS_H_ */
