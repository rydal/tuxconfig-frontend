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

    introTab *intro_tab = new introTab(tabWidget);
    tabWidget->addTab(intro_tab,"Description");


    RunTab *runTab = new RunTab(tabWidget);
    QScrollArea* contactScrollArea = new QScrollArea();
    contactScrollArea->setWidget(runTab);
    contactScrollArea->setMinimumSize( QSize( 640, 480) );
    contactScrollArea->setWidgetResizable(true);
    tabWidget->addTab(contactScrollArea,"General");

    RestoreTab *restore_tab = new RestoreTab(tabWidget);

    tabWidget->addTab(restore_tab,"Restore");

    ConsoleTab *console_tab = new ConsoleTab(tabWidget);

    tabWidget->addTab(console_tab,"Console");

    ContributorTab2 *contributor_tab = new ContributorTab2(tabWidget);
    tabWidget->addTab(contributor_tab,"Contributor");

            QVBoxLayout *mainLayout = new QVBoxLayout;
                mainLayout->addWidget(tabWidget);

                setLayout(mainLayout);

                setWindowTitle(tr("Tab Dialog"));

                connect(runTab, SIGNAL(setTab(int)), this, SLOT(changeTab(int)));
                connect(console_tab, SIGNAL(setTab(int)), this, SLOT(changeTab(int)));
                connect(restore_tab, SIGNAL(setTab(int)), this, SLOT(changeTab(int)));
                connect(intro_tab, SIGNAL(setTab(int)), this, SLOT(changeTab(int)));
                connect(runTab, SIGNAL(sendCommand(Device, string, vector<string>)), this, SLOT(runCommand(Device, string, vector<string>)));
                connect(console_tab, SIGNAL(updateScreen()),  this, SLOT(updateContributor()));
                connect(restore_tab, SIGNAL(updateScreen()),  this, SLOT(updateContributor()));

                connect(this, SIGNAL(updatedContributor(Device)),  contributor_tab, SLOT(updateScreen(Device)));

                connect(this, SIGNAL(showButtons(vector<string>, bool)),console_tab,SLOT(showButtons(vector<string>,bool)));
                connect(this, SIGNAL(sendToConsole(Device, string, vector<string>)),console_tab,SLOT(sendToConsole(Device, string, vector<string>)));

                connect(restore_tab, SIGNAL(sendCommand(Device, string, vector<string>)),console_tab,SLOT(sendToConsole(Device, string, vector<string>)));
                connect(console_tab, SIGNAL(refreshRestore(string)),  restore_tab, SLOT(update(string)));
                connect(console_tab, SIGNAL(sendReboot()),  contributor_tab, SLOT(receiveReboot()));

    }


void NotebookGUI::changeTab(int index) {
    tabWidget->setCurrentIndex(index);
}
void NotebookGUI::showResultButtons()  {
    emit showButtons(install_details, true);

}
void NotebookGUI::showFailButton()  {
    emit showButtons(install_details, false);

}
void NotebookGUI::runCommand(Device device, string method, vector<string> parameters) {

    this->current_device = device;
    this->install_method = method;
    this->install_details = parameters;
    emit sendToConsole(device, method, parameters);

}

void NotebookGUI::updateContributor() {
    emit updatedContributor(current_device);
}


