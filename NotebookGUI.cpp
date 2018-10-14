/*
 * NotebookGUI.cpp
 *
 *  Created on: 30 Sep 2018
 *      Author: roberty
 */

#include "NotebookGUI.h"

    NotebookGUI::NotebookGUI(const QString name ) {
    tabWidget = new QTabWidget;

    setWindowTitle("Tuxconfig");

    QFileInfo fileInfo(name);
    RunTab *runTab = new RunTab(fileInfo,tabWidget);
    runTab->setObjectName("RunTab");
    tabWidget->addTab(runTab,"General");
    tabWidget->addTab(new RestoreTab(fileInfo), "Restore");

    ConsoleTab *consoleTab = new ConsoleTab(fileInfo,tabWidget);
    runTab->setObjectName("ConsoleTab");
    tabWidget->addTab(consoleTab,"Console");

    tabWidget->addTab(new ContributorTab2(fileInfo),"Contributor info");

		    QVBoxLayout *mainLayout = new QVBoxLayout;
		        mainLayout->addWidget(tabWidget);

		        setLayout(mainLayout);

		        setWindowTitle(tr("Tab Dialog"));

                connect(runTab, SIGNAL(setTab(int)), this, SLOT(changeTab(int)));
                connect(consoleTab, SIGNAL(setTab(int)), this, SLOT(changeTab(int)));

                connect(runTab, SIGNAL(setDevice(Device)), this, SLOT(setDevice(Device)));



}
void NotebookGUI::changeTab(int index) {
    tabWidget->setCurrentIndex(index);
}
void NotebookGUI::setDevice(Device device) {
}


