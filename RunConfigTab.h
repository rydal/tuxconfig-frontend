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
     /** Constructor.
      * @brief RunTab
      */
     RunTab();
     /**
      * @brief RunTab
      * @param parent
      */
     RunTab( QWidget *parent = 0);
     /** Sets layout of devices with install options.
      * @brief updateLayout
      */
     void updateLayout();
     QWidget *m_parent;
     QTabWidget *tabWidget;
    QTermWidget *termWidget;
    QVBoxLayout *mainLayout;
    /** Clears widgets when refreshing.
 * @brief clearLayout
 * @param layout
 * @param deleteWidgets
 */
void clearLayout(QLayout* layout, bool deleteWidgets = true);

 public slots:
      /** fires install event in runconfig class.
      * @brief installButton
      */
     void installButton(Device);
     /** fires uninstall event in runconfig class.
      * @brief uninstallButton
      */
     void uninstallButton(Device);
     /** fires upgrade event in runconfig class.
      * @brief upgrade
      */
     void upgrade(Device);


signals:
     /** sets tab by index.
      * @brief setTab
      */
     void setTab(int);
     /** sends details to console tab for it to excecute scripts successfully.
      * @brief sendCommand
      */
     void sendCommand(Device, string, vector<string>);


 protected:

 };

#endif /* CONSOLETAB_H_ */

