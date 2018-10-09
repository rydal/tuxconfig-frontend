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
#include "RestoreGUI.h"
#include "QuestionBox.h"

class LinuxConf {
public:

 static void on_button_clicked(std::string command,Device& device);
};

#endif /* LINUXCONF_H_ */
