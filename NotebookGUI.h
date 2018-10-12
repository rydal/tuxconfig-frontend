/*
 * NotebookGUI.h
 *
 *  Created on: 30 Sep 2018
 *      Author: roberty
 */

#ifndef NOTEBOOKGUI_H_
#define NOTEBOOKGUI_H_


#include <QApplication>

#include <string>
#include <map>
#include <iterator>
#include "device.h"
#include "GetHistory.h"
#include "GetLocalDevices.h"
#include "GetRemoteConfig.h"
#include <set>
#include "RestoreTab.h"
#include "ConsoleTab.h"
#include "ContributorTab2.h"
#include "GeneralTab.h"


using namespace std;
class NotebookGUI :  public QDialog {
public:
    explicit NotebookGUI(const QString name, QWidget *parent = 0);
	 void changeTab(int index);
	 QTabWidget *tabWidget;
	protected:
	  //Signal handlers:
	  void on_button_quit();

	  void restore_button_clicked(string command, Device device);
	  void main_button_clicked(string command);
	  void on_child_exited();
	  void get_result_gui(string message);
	  void get_result(string message);
	  //Child widgets:


};

#endif /* NOTEBOOKGUI_H_ */
