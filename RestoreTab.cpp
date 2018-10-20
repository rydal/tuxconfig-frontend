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


								QPushButton *restore_button = new QPushButton(QString::fromStdString("restore"));

                                if (it->second.isIsInstalled()) {
									installed_status->setText("Installed");
								} else if (it->second.getAttemptedInstall()) {
                                    installed_status->setText("Attempted Install");
								}

								GetRemoteConfig get_config_class;


								m_Grid->addWidget(description);
								m_Grid->addWidget(devicename);

								m_Grid->addWidget(restore_button);
                                connect(restore_button, &QPushButton::clicked, [=] { DoRestore(it->second); });



							mainLayout->addLayout(m_Grid);
				}
				setLayout(mainLayout);
				 // Set layout in QWidget


}

string RestoreTab::DoRestore(Device device) {
    string found_files = "find /var/lib/tuxconfig/ -name \"" + device.getDeviceid() + "-*.tar\" -printf \"%T@  %p\n\" | sort -n | head -1 | sed 's/^ *//'| cut -d\" \" -f2- ";
    string restorefile = GetOS::exec(found_files.c_str());

        string runfile = "";
        runfile += "#! /bin/bash \n";
        runfile += "set -e \n";

        runfile += "exec > >(tee -i /var/lib/tuxconfig/" + device.getDeviceid() + "-uninstall.log) \n";
        runfile += "function cleanup() { \n";
        runfile += "kill -SIGUSR2 " + to_string(::getpid()) + " \n";
        runfile += "} \n";
        runfile += "tar -C / -xvf /var/lib/tuxconfig/backup/" + restorefile + "\n";

        string restore_run_file = "/usr/src/tuxconfig-" + device.getDeviceid() + "-restore";
            std::ofstream out(restore_run_file);
            out << runfile;
            out.close();
            return restore_run_file;


}

