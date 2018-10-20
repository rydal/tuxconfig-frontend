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
    ConsoleTab(const QFileInfo &fileInfo, QWidget *m_parent);
     void setDevice(Device device);
    QWidget *parent;
     QTermWidget *console;
     QGridLayout *mainLayout;
     QPushButton *works_button;
     QPushButton *fails_button ;
     QLabel *success_label;
    void fails_result();
    void works_result();
    Device current_device;

signals:
     void setTab(int);
     void updateScreen();

public slots:
     void showButtons(vector<string> details, bool success);
     void sendToConsole(Device device,string method, vector<string> parameters);

};

#endif /* CONSOLETAB_H_ */
