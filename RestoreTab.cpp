/*: QDialog(parent) {
 * RestoreTab.cpp
 *
 *  Created on: 4 Oct 2018
 *      Author: roberty
 */

#include "RestoreTab.h"

RestoreTab::RestoreTab(const QFileInfo &fileInfo, QWidget *parent)

{

	// TODO Auto-generated constructor stub
	std::map<string,Device> hashmap = GetHistory::getInstalledDevices();

		 QPushButton *button = new QPushButton(QString::fromStdString("close"));
		 	  QVBoxLayout *mainLayout = new QVBoxLayout;

				for (std::map<string,Device>::iterator it=hashmap.begin(); it!=hashmap.end(); ++it) {
					QHBoxLayout* m_Grid = new QHBoxLayout;
								QLabel *description = new QLabel(QString::fromStdString(it->second.getDescription()));
								QLabel *devicename = new QLabel(QString::fromStdString(it->second.getDevicename()));
								QLabel *installed_status = new QLabel;

                                description->setAlignment(Qt::AlignCenter);
                                devicename->setAlignment(Qt::AlignCenter);
                                installed_status->setAlignment(Qt::AlignCenter);


                                QPushButton *restore_button1 = new QPushButton(QString::fromStdString("restore"));

                                if (it->second.isIsInstalled()) {
									installed_status->setText("Installed");
                                }



								m_Grid->addWidget(description);
								m_Grid->addWidget(devicename);

                                m_Grid->addWidget(restore_button1);
                                Device& tmp_device = it->second;
                                connect(restore_button1, &QPushButton::clicked, [=] { RestoreButton(tmp_device); });



							mainLayout->addLayout(m_Grid);
				}
				setLayout(mainLayout);
				 // Set layout in QWidget


}

void RestoreTab::RestoreButton(Device device) {

vector<string> parameters = RunConfig::restore(device);

    emit    sendCommand(device, "restore", parameters );
    emit setTab(2);


}

