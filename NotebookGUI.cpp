/*
 * NotebookGUI.cpp
 *
 *  Created on: 30 Sep 2018
 *      Author: roberty
 */

#include "NotebookGUI.h"

    NotebookGUI::NotebookGUI(const QString name, QWidget *parent ) {
    tabWidget = new QTabWidget;

    setWindowTitle("Tuxconfig");


    QFileInfo fileInfo(name);
	   tabWidget->addTab(new RestoreTab(fileInfo), "Restore");

    tabWidget->addTab(new RunTab(fileInfo),"General");
		    tabWidget->addTab(new ConsoleTab(fileInfo,tabWidget),"Configure");
		    tabWidget->addTab(new ContributorTab2(fileInfo),"Contributor info");

		    QVBoxLayout *mainLayout = new QVBoxLayout;
		        mainLayout->addWidget(tabWidget);

		        setLayout(mainLayout);

		        setWindowTitle(tr("Tab Dialog"));


}
void NotebookGUI::changeTab( int index) {
tabWidget->setCurrentIndex(index);
}
