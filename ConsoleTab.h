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
void RebootMachine();

/**
 * @brief ConsoleTab::clearLayout
 * @param layout
 * @param deleteWidgets
 * Clears the layout for future method calls.
 */
void clearLayout(QLayout* layout, bool deleteWidgets);

signals:

     void setTab(int);

     void updateScreen();
     void refreshRestore(string);
     void sendReboot();

public slots:
     /** On reciept of sugusr1 this method displays the success and fail buttons
     * @brief
     * @param details
     * @param success
     */
     void showButtons(vector<string> details, bool success);
     /**
      * Recieves a message from other tabs then executes the command in the parameters tab.
      * sets the install method and current device to the class instance.
      * @brief ConsoleTab::sendToConsole
      * @param device
      * @param method
      * @param parameters
      */
     void sendToConsole(Device device,string method, vector<string> parameters);


};

#endif /* CONSOLETAB_H_ */
