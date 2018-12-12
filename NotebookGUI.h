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
#include "introtab.h"


using namespace std;
class NotebookGUI :  public QDialog {
        Q_OBJECT

public:
    /** Constructor.
    /** * @brief NotebookGUI
    */
    NotebookGUI();
    /** Constructor, casts parameter to QString.
     * @brief NotebookGUI
     * @param name
     */
    explicit NotebookGUI(const QString name);

     QTabWidget *tabWidget;
     /** receives a signal from linuxconf (main), shows success and fail buttons
      * @brief showResultButtons
      */
     void showResultButtons();
     /** receives a signal from linuxconf (main), shows and fail button and fail text
      * @brief showFailButton
      */
     void showFailButton();
     void updates_available();
signals:
     /** sets contributor details tab information and switches tabs.
      * @brief updatedContributor
      * @param device
      */
     void updatedContributor(Device device);
     /** Shows button information on consoleTab.
      * @brief showButtons
      */
     void showButtons(vector<string>, bool);
     /** Not used.
      * @brief updateDevice
      */
     void updateDevice(Device);
     /** sends details to consoleTab for scripts to run.
      * @brief sendToConsole
      */
     void sendToConsole(Device, string, vector<string>);
     void updates_available_signal();

public slots:
     /** Change tab by index.
     * @brief changeTab
     * @param index
     */
    void changeTab(int index);
    /** Sets class variables for parameters and emits sendToConsole() with these.
     * @brief runCommand
     * @param device
     * @param method
     * @param parameters
     */
    void runCommand(Device device, string method, vector<string> parameters);
    /** Receives signal then updates contributor tab with contributor details.
     * @brief updateContributor
     */
    void updateContributor();

protected:
    Device current_device;
    string install_method;
    vector<string> install_details;



};

#endif /* NOTEBOOKGUI_H_ */
