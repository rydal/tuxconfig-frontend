/*
 * ConsoleTab.h
 *
 *  Created on: 5 Oct 2018
 *      Author: roberty
 */

#ifndef CONSOLETAB_H_
#define CONSOLETAB_H_

#include <QApplication>
#include <QtWidgets>
#include <QKeySequence>
#include <QtWidgets>
#include<qtermwidget5/qtermwidget.h>
#include "NotebookGUI.h"
#include <csignal>
#include "Feedback.h"
#include "device.h"
class ConsoleTab : public QWidget {
    Q_OBJECT
public:
    /** Console widget, embeds a qtermwidget in this tab.
     @brief
     @param m_parent
*/
    ConsoleTab( QWidget *m_parent);

    /** Sets the device to be operated on
      * @brief setDevice
      * @param device
      */
     void setDevice(Device device);
    QWidget *parent;
     QTermWidget *console;
     QGridLayout *mainLayout;
     QPushButton *works_button;
     QPushButton *fails_button ;
     QLabel *success_label;
     QLabel *reboot_label;
     QLabel *done_label;

     QPushButton *reboot_button;
     /**
       Fires when fail button is pressed.
       Sends device with success status to feedback class.
       hides butons and switches to recover tab

     */
    void fails_result();
    /**
    Fires when success button is pressed. hides buttons and switches to contributor tab.
    Sends device with success status to feedback class.
    Removes load on restart feature.
    */
    void works_result();
    Device current_device;
    string install_method;
    /** reboots machine
     */
void RebootMachine();

/** Clears the layout of the tab.
 * @brief ConsoleTab::clearLayout
 * @param layout conainer to be removed.
 * @param deleteWidgets Delete widgets as well as layout.
 * Clears the layout for future method calls.
 */
void clearLayout(QLayout* layout, bool deleteWidgets);

signals:
    /** signal to set tab
     */
     void setTab(int);
    /** signal to update contributor tab
     */
     void updateScreen();
     /** signal to refresh the restore screen
      */
     void refreshRestore(string);
     /** signal to reboot the machine.
      */
     void sendReboot();

public slots:
     /** On reciept of sugusr1 this method displays the success and fail buttons
     * @brief
     * @param details device install set.
     * @param success succes of install.
     */
     void showButtons(vector<string> details, bool success);
     /**
      * Recieves a message from other tabs then executes the command in the parameters tab.
      * sets the install method and current device to the class instance.
      * @brief ConsoleTab::sendToConsole
      * @param device device.
      * @param method install, uninstall or restore.
      * @param parameters runfile name, test program, test message, restart?
      */
     void sendToConsole(Device device,string method, vector<string> parameters);


};

#endif /* CONSOLETAB_H_ */
