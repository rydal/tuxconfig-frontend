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

public:
    ConsoleTab(const QFileInfo &fileInfo, QTabWidget *m_tabWidget, QWidget *parent = 0 );
    QWidget *parent;
    QTabWidget *tabWidget;
    void move_tabs();
};

#endif /* CONSOLETAB_H_ */
