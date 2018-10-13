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
class ConsoleTab : public QWidget {
    Q_OBJECT

public:
    ConsoleTab(const QFileInfo &fileInfo, QWidget *m_parent);
     void  RunInstallConfig(Device device);
    QWidget *parent;
    QTabWidget *tabWidget;
     QTermWidget *console;
    void move_tabs(int index);

};

#endif /* CONSOLETAB_H_ */
