/*
 * NotebookGUI.cpp
 *
 *  Created on: 30 Sep 2018
 *      Author: roberty
 */

#include "NotebookGUI.h"

NotebookGUI::NotebookGUI() {
    tabWidget = new QTabWidget;




			   tabWidget->addTab(new DefaultTab(),"General");
			   tabWidget->addTab(new RestoreTab(), "Restore");
			   tabWidget->addTab(new ConsoleTab(),"Configure");
			   tabWidget->addTab(new ContributorTab2(),"Contibutor");


}

NotebookGUI::~NotebookGUI() {
	// TODO Auto-generated destructor stub
}
