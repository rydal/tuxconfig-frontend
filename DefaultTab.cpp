/*
 * DefaultTab.cpp
 *
 *  Created on: 7 Oct 2018
 *      Author: roberty
 */

#include "DefaultTab.h"

DefaultTab::DefaultTab() {
	// TODO Auto-generated constructor stub

	 QPushButton *button = new QPushButton("close");
			 	  QVBoxLayout *mainLayout = new QVBoxLayout;

	set<Device> local_devices = GetLocalDevices::listdevices();
	set<Device> remote_devices;

		for (auto device : local_devices) {

			remote_devices.insert(GetRemoteConfig::GetConfiguration(device));

		}
	for (auto iterated_device : remote_devices) {

		QVBoxLayout* m_Grid = new QVBoxLayout;
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
			}

			mainLayout->addLayout(m_Grid);

			install_button->connect(install_button, SIGNAL (released()),this, SLOT (handleButton("install",iterated_device)));
			uninstall_button->connect(uninstall_button, SIGNAL (released()),this, SLOT (handleButton("uninstall",iterated_device)));
			restore_button->connect(restore_button, SIGNAL (released()),this, SLOT (handleButton("restore",iterated_device)));
			upgrade_button->connect(upgrade_button, SIGNAL (released()),this, SLOT (handleButton("upgrade",iterated_device)));


		}





}

DefaultTab::~DefaultTab() {
	// TODO Auto-generated destructor stub
}

