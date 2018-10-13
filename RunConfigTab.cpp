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
            QObject::connect(install_button, SIGNAL(clicked(Device*)),this, SLOT(installButton(Device*)));





		}
	}


 void RunTab::installButton(Device *device) {
     QList<QTermWidget*> widgetList = m_parent->findChildren<QTermWidget*>();
    widgetList.at(0)->sendText("hello");
     emit foo();
 }
 void RunTab::uninstallButton(Device* device) {

  }
 void RunTab::restoreButton(Device* device) {

  }
 void RunTab::upgradeButton(Device* device) {

  }

