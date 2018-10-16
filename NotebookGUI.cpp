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
    QScrollArea* contactScrollArea = new QScrollArea();
    contactScrollArea->setWidget(runTab);
    contactScrollArea->setMinimumSize( QSize( 1024, 768) );

    tabWidget->addTab(contactScrollArea,"General");
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

                connect(runTab, SIGNAL(sendCommand(Device, string, string)), this, SLOT(runCommand(Device, string, string)));



}
void NotebookGUI::setDevice(Device device, string* m_test_parameters) {
    current_device = device;
    test_parameters = m_test_parameters;
}

void NotebookGUI::changeTab(int index) {
    tabWidget->setCurrentIndex(index);
}
void NotebookGUI::showResultButtons()  {
    QList<QWidget*> worksList = tabWidget->findChildren<QWidget*>("works_button");
    QList<QWidget*> failsList = tabWidget->findChildren<QWidget*>("fails_button");
    QList<QLabel*> successList = tabWidget->findChildren<QLabel*>("success_label");

    worksList.at(0)->setVisible(true);
    failsList.at(0)->setVisible(true);
    successList.at(0)->setText(test_parameters[1].c_str());

}
void NotebookGUI::runCommand(Device device, string method, string command) {
    QList<QTermWidget*> widgetList = tabWidget->findChildren<QTermWidget*>();
    if (method == "null") {
        widgetList.at(0)->sendText(command.c_str());
        widgetList.at(0)->sendText("\r");
    } else {
    string runstring = command + " | tee /var/log/tuxconfig/" + device.getDeviceid() + "-" + method;
    widgetList.at(0)->sendText(runstring.c_str());
    widgetList.at(0)->sendText("\r");
}
}
