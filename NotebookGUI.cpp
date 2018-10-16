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

                connect(runTab, SIGNAL(sendCommand(Device, string, string)), this, SLOT(runCommand(Device, string, string)));



}
void NotebookGUI::changeTab(int index) {
    tabWidget->setCurrentIndex(index);
}
void NotebookGUI::showResultButtons()  {
    QList<QWidget*> worksList = tabWidget->findChildren<QWidget*>("works_button");
    QList<QWidget*> failsList = tabWidget->findChildren<QWidget*>("fails_button");
    worksList.at(0)->setVisible(true);
    failsList.at(0)->setVisible(true);
}
void NotebookGUI::showErrorButton()  {
    QList<QWidget*> widgetList = tabWidget->findChildren<QWidget*>("fails_button");
    cout<<"butons?"<<widgetList.size()<<endl;
}
void NotebookGUI::runCommand(Device device, string method, string command) {
    QList<QTermWidget*> widgetList = tabWidget->findChildren<QTermWidget*>();
    string runstring = command + " | tee /var/log/tuxconfig/" + device.getDeviceid() + "-" + method;
    widgetList.at(0)->sendText(runstring.c_str());
    widgetList.at(0)->sendText("\r");

}
