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

    QPushButton *button;
    QFileInfo fileInfo(name);
    RunTab *runTab = new RunTab(fileInfo,tabWidget);
    QScrollArea* contactScrollArea = new QScrollArea();
    contactScrollArea->setWidget(runTab);
    contactScrollArea->setMinimumSize( QSize( 1024, 768) );

    tabWidget->addTab(contactScrollArea,"General");
    tabWidget->addTab(new RestoreTab(fileInfo), "Restore");

    ConsoleTab *console_tab = new ConsoleTab(fileInfo,tabWidget);

    tabWidget->addTab(console_tab,"Console");

    ContributorTab2 *contributor_tab = new ContributorTab2(fileInfo,tabWidget);
    tabWidget->addTab(contributor_tab,"Contributor");

		    QVBoxLayout *mainLayout = new QVBoxLayout;
                mainLayout->addWidget(tabWidget);

                setLayout(mainLayout);

                setWindowTitle(tr("Tab Dialog"));

                connect(runTab, SIGNAL(setTab(int)), this, SLOT(changeTab(int)));
                connect(console_tab, SIGNAL(setTab(int)), this, SLOT(changeTab(int)));

                connect(runTab, SIGNAL(sendCommand(Device, string, vector<string>)), this, SLOT(runCommand(Device, string, vector<string>)));
                connect(console_tab, SIGNAL(updateScreen()),  this, SLOT(updateContributor()));
                connect(this, SIGNAL(updatedContributor(Device)),  contributor_tab, SLOT(updateScreen(Device)));

                connect(this, SIGNAL(showButtons(vector<string>, bool)),console_tab,SLOT(showButtons(vector<string>,bool)));

    }


void NotebookGUI::changeTab(int index) {
    tabWidget->setCurrentIndex(index);
}
void NotebookGUI::showResultButtons()  {
    emit showButtons(install_details, true);

}

void NotebookGUI::runCommand(Device device, string method, vector<string> parameters) {
    QList<QTermWidget*> widgetList = tabWidget->findChildren<QTermWidget*>();
    if (method == "install") {
        string  install_command = parameters.at(0) + " ; " + parameters.at(1);
        widgetList.at(0)->sendText(install_command.c_str());
        widgetList.at(0)->sendText("\r");
    } else {
    widgetList.at(0)->sendText(parameters.at(0).c_str());
    widgetList.at(0)->sendText("\r");
}

    this->current_device = device;
    this->install_method = method;
    this->install_details = parameters;

}

void NotebookGUI::updateContributor() {
    emit updatedContributor(current_device);
}


