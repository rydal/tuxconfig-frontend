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
#include "RunConfigTab.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds


using namespace std;
class NotebookGUI :  public QDialog {
        Q_OBJECT

public:
    void setDevice(Device device, string* test_parameters);
    NotebookGUI();
    explicit NotebookGUI(const QString name);

     QTabWidget *tabWidget;
     void showResultButtons();
     void showFailButton();

signals:
     void updatedContributor(Device device);
     void showButtons(vector<string>, bool);

public slots:
    void changeTab(int index);
    void runCommand(Device device, string method, vector<string> parameters);
    void updateContributor();

protected:
    Device current_device;
    string install_method;
    vector<string> install_details;



};

#endif /* NOTEBOOKGUI_H_ */
