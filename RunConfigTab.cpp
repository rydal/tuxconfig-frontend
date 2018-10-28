/*
 * DefaultTab.cpp
 *
 *  Created on: 7 Oct 2018
 *      Author: roberty
 */

#include "RunConfigTab.h"


 RunTab::RunTab( QWidget * m_parent)
     : QWidget(m_parent)
 {
    mainLayout = new QVBoxLayout;
    updateLayout();

}
 void RunTab::updateLayout() {
	set<Device> local_devices = GetLocalDevices::listdevices();
	set<Device> remote_devices;

		for (auto device : local_devices) {

			remote_devices.insert(GetRemoteConfig::GetConfiguration(device));

		}
	for (auto iterated_device : remote_devices) {

        QGridLayout* m_Grid = new QGridLayout;
			QLabel* description = new QLabel;
			QLabel* devicename = new QLabel;
			QPushButton* upgrade_button = new QPushButton(QString::fromStdString("upgrade"));
            QPushButton* install_button = new QPushButton(QString::fromStdString("replace"));
            QPushButton* uninstall_button = new QPushButton(QString::fromStdString("uninstall"));
            QPushButton* reinstall_button = new QPushButton(QString::fromStdString("reinstall"));
            description->setAlignment(Qt::AlignLeft);
            devicename->setAlignment(Qt::AlignLeft);
            description->setFixedWidth(200);
            devicename->setFixedWidth(500);


			description->setText(QString::fromStdString(iterated_device.getDescription()));
			devicename->setText(QString::fromStdString(iterated_device.getDevicename() + ":"));

            m_Grid->addWidget(description,0,0,1,1);
            m_Grid->addWidget(devicename,0,1,1,1);



            if (iterated_device.getGitUrl() != "null" && iterated_device.isIsInstalled() == false) {
            m_Grid->addWidget(install_button,0,2,1,1);
            }
            if (iterated_device.getGitUrl() != "null" && iterated_device.isIsInstalled() == true) {
            m_Grid->addWidget(reinstall_button,0,3,1,1);
            }

            if (iterated_device.isUpgradeable() == true) {
                m_Grid->addWidget(upgrade_button,0,4,1,1);

            }
            if (iterated_device.isIsInstalled() == true) {
                m_Grid->addWidget(uninstall_button,0,4,1,1);
            }


			mainLayout->addLayout(m_Grid);
            setLayout(mainLayout);
 connect(install_button, &QPushButton::clicked, [=] { installButton(iterated_device); });
 connect(upgrade_button, &QPushButton::clicked, [=] { upgrade(iterated_device); });
 connect(reinstall_button, &QPushButton::clicked, [=] { installButton(iterated_device); });
 connect(uninstall_button, &QPushButton::clicked, [=] { uninstallButton(iterated_device); });


  }


    QPushButton* updateButton = new QPushButton(QString::fromStdString("Rescan USB bus"));
    mainLayout->addWidget(updateButton);
    connect(updateButton, &QPushButton::clicked, [=] { clearLayout(mainLayout) ;updateLayout();});

 }


 void RunTab::installButton(Device device) {
     vector<string> install = RunConfig::install(device);
        emit setTab(3);

     emit sendCommand(device, "install",install);


 }
 void RunTab::uninstallButton(Device device) {
     vector<string> uninstall = RunConfig::uninstall(device);

     emit setTab(3);
     emit sendCommand(device, "uninstall", uninstall);
  }

 void RunTab::upgrade(Device device) {
     vector<string>   upgrade = RunConfig::upgrade(device);
     emit setTab(3);
     emit sendCommand(device, "upgrade",upgrade);

  }

 void RunTab::clearLayout(QLayout* layout, bool deleteWidgets)
 {
     while (QLayoutItem* item = layout->takeAt(0))
     {
         if (deleteWidgets)
         {
             if (QWidget* widget = item->widget())
                 widget->deleteLater();
         }
         if (QLayout* childLayout = item->layout())
             clearLayout(childLayout, deleteWidgets);
         delete item;
     }
 }

