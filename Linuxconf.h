/*
 * Linuxconf.h
 *
 *  Created on: 27 Aug 2018
 *      Author: roberty
 */

#ifndef LINUXCONF_H_
#define LINUXCONF_H_



#include <QtWidgets>
#include "CheckConnection.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include "GetOS.h"
#include "RunConfig.h"

#include <iterator>
#include <unistd.h>
#include <stdlib.h>
#include <map>
#include "device.h"
#include "NotebookGUI.h"
#include "RestoreCmd.h"
#include "QuestionBox.h"
#include "ConsoleTab.h"

#include <csignal>

class LinuxConf {
public:
NotebookGUI gui;
/** runs action based on button clicked. one of install, uninstall, restore or upgrade.
  * @brief on_button_clicked
  * @param command
  * @param device
  */
 static void on_button_clicked(std::string command,Device& device);
 static int attempt_number;

};

#endif /* LINUXCONF_H_ */
