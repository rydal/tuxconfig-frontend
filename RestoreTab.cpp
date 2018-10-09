/*
 * RestoreTab.cpp
 *
 *  Created on: 4 Oct 2018
 *      Author: roberty
 */

#include "RestoreTab.h"

RestoreTab::RestoreTab() {
	// TODO Auto-generated constructor stub
	std::map<string,Device> hashmap = GetHistory::getInstalledDevices();

		 QPushButton *button = new QPushButton(QString::fromStdString("close"));
		 	  QVBoxLayout *mainLayout = new QVBoxLayout;

				for (std::map<string,Device>::iterator it=hashmap.begin(); it!=hashmap.end(); ++it) {
					QHBoxLayout* m_Grid = new QHBoxLayout;
								QLabel *description = new QLabel(QString::fromStdString(it->second.getDescription()));
								QLabel *devicename = new QLabel(QString::fromStdString(it->second.getDevicename()));
								QLabel *installed_status = new QLabel;

								QPushButton *restore_button = new QPushButton(QString::fromStdString("restore"));
								if (it->second.isIsInstalled()) {
									installed_status->setText("Installed");
								} else if (it->second.getAttemptedInstall()) {
									installed_status->setText("Installed");
								}

								GetRemoteConfig get_config_class;


								m_Grid->addWidget(description);
								m_Grid->addWidget(devicename);

								m_Grid->addWidget(restore_button);



							mainLayout->addLayout(m_Grid);
							//restore_button->signal_clicked().connect( sigc::bind<Glib::ustring>( sigc::mem_fun(*this, &RestoreGUI::on_button_clicked), "restore",it->second) );
				}


}

RestoreTab::~RestoreTab() {
	// TODO Auto-generated destructor stub
}

