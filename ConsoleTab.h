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
#include "enums.h"

class ConsoleTab : public QWidget {
    Q_OBJECT

public:
    ConsoleTab(const QFileInfo &fileInfo, QWidget *m_parent);
     void  RunInstallConfig(Device device);
    QWidget *parent;
     QTermWidget *console;
     QVBoxLayout *mainLayout;
     QPushButton *works_button;
     QPushButton *fails_button ;
    void move_tabs(int index);
    void setDevice(Device device);
    void setResponseButtons();


signals:
     void setTab(int);
};

#endif /* CONSOLETAB_H_ */
