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
#include "ConsoleTab.h"


 class RunTab : public QWidget
 {
Q_OBJECT

 public:
     RunTab();
     RunTab(const QFileInfo &fileInfo, QWidget *parent = 0);
     QWidget *m_parent;
     QTabWidget *tabWidget;
    QTermWidget *termWidget;

 public slots:
     void installButton(Device);
     void uninstallButton(Device);

     void upgrade(Device);


signals:
     void setTab(int);
     void sendCommand(Device, string, vector<string>);


 protected:

 };

#endif /* CONSOLETAB_H_ */

