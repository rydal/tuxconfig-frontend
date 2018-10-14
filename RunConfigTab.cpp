/*
 * DefaultTab.cpp
 *
 *  Created on: 7 Oct 2018
 *      Author: roberty
 */

#include "RunConfigTab.h"


 RunTab::RunTab(const QFileInfo &fileInfo, QWidget * m_parent)
     : QWidget(m_parent), m_parent(m_parent)

 {
  QVBoxLayout *mainLayout = new QVBoxLayout;

	set<Device> local_devices = GetLocalDevices::listdevices();
	set<Device> remote_devices;

		for (auto device : local_devices) {

			remote_devices.insert(GetRemoteConfig::GetConfiguration(device));

		}
	for (auto iterated_device : remote_devices) {

		QHBoxLayout* m_Grid = new QHBoxLayout;
			QLabel* description = new QLabel;
			QLabel* devicename = new QLabel;
			QPushButton* upgrade_button = new QPushButton(QString::fromStdString("upgrade"));
			QPushButton* install_button = new QPushButton(QString::fromStdString("install"));
			QPushButton* uninstall_button = new QPushButton(QString::fromStdString("uninstall"));
			QPushButton* restore_button = new QPushButton(QString::fromStdString("restore"));

			description->setText(QString::fromStdString(iterated_device.getDescription()));
			devicename->setText(QString::fromStdString(iterated_device.getDevicename() + ":"));

			m_Grid->addWidget(description);
			m_Grid->addWidget(devicename);

			if (iterated_device.getGitUrl() != "null") {
				m_Grid->addWidget(install_button);
			}
			if (iterated_device.getModulename() != "null") {
				m_Grid->addWidget(uninstall_button);
			}
			if (iterated_device.getAttemptedInstall() == true) {
				m_Grid->addWidget(restore_button);
			}
			if (iterated_device.isUpgradeable() == true) {
				m_Grid->addWidget(upgrade_button);
			}	 QPushButton *button = new QPushButton("close");


			mainLayout->addLayout(m_Grid);
            setLayout(mainLayout);
 connect(install_button, &QPushButton::clicked, [=] { installButton(iterated_device); });
connect(uninstall_button, &QPushButton::clicked, [=] { uninstallButton(iterated_device); });
connect(restore_button, &QPushButton::clicked, [=] { restoreButton(iterated_device); });
connect(upgrade_button, &QPushButton::clicked, [=] { upgradeButton(iterated_device); });

QList<QTermWidget*> widgetList = m_parent->findChildren<QTermWidget*>();
termWidget = widgetList.at(0);

  }

 }


 void RunTab::installButton(const Device& device) {
     string* install_result = RunConfig::install(device);
        termWidget->sendText(install_result[0].c_str());
        termWidget->sendText("\r");
        emit setTab(2);
 }
 void RunTab::uninstallButton(const Device& device) {
     string uninstall_command = RunConfig::uninstall(device);

     termWidget->sendText(uninstall_command.c_str());
     termWidget->sendText("\r");
     emit setTab(2);

  }
 void RunTab::restoreButton(const Device& device) {
     string restore_command = RunConfig::restore(device);
     termWidget->sendText(restore_command.c_str());
     termWidget->sendText("\r");
     emit setTab(2);

  }
 void RunTab::upgradeButton(const Device& device) {
     string upgrade_command = RunConfig::upgrade(device);
     termWidget->sendText(upgrade_command.c_str());
     termWidget->sendText("\r");
     emit setTab(2);

  }


