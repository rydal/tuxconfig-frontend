/*
 * DefaultTab.h
 *
 *  Created on: 7 Oct 2018
 *      Author: roberty
 */
#ifndef GENERALTAB_H_
#define GENERALTAB_H_

#include <QtGui>
#include <QtWidgets>
#include <string>
#include <map>
#include <iterator>
#include "device.h"
#include "GetLocalDevices.h"
#include "GetRemoteConfig.h"
#include "NotebookGUI.h"
#include "RunConfig.h"


 class RunTab : public QWidget
 {

 public:
     RunTab(const QFileInfo &fileInfo, QWidget *parent = 0);
     void installButton(Device device);
     void uninstallButton(Device device);
     void restoreButton(Device device);
     void upgradeButton(Device device);
 protected:

 };

#endif /* CONSOLETAB_H_ */

