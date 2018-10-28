/*: QDialog(parent) {
 * RestoreTab.cpp
 *
 *  Created on: 4 Oct 2018
 *      Author: roberty
 */

#include "RestoreTab.h"

RestoreTab::RestoreTab( QWidget *parent)

{

update();

}

void RestoreTab::update() {
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
                                QPushButton *success_button = new QPushButton(QString::fromStdString("Successful install"));
                                QPushButton *fail_button = new QPushButton(QString::fromStdString("Failed install"));


                                 installed_status->setText(QString::fromStdString(it->second.getStatus()));

                                m_Grid->addWidget(description);
                                m_Grid->addWidget(devicename);
                                m_Grid->addWidget(installed_status);
                                m_Grid->addWidget(restore_button1);
                                bool installed = false;
                                if (it->second.getStatus() == "works" || it->second.getStatus() == "failed")
                                    installed = true;
                                    if (! installed) {
                                m_Grid->addWidget(success_button);
                                m_Grid->addWidget(fail_button);
                                }

                                Device& tmp_device = it->second;
                                connect(restore_button1, &QPushButton::clicked, [=] { RestoreButton(tmp_device); });
                                connect(success_button, &QPushButton::clicked, [=] { SuccessButton(tmp_device); });
                                connect(fail_button, &QPushButton::clicked, [=] { FailButton(tmp_device); });


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

void RestoreTab::SuccessButton(Device device) {
    Feedback(device,true);
    emit setTab(4);
    GetOS::reset_reboot();
    }

void RestoreTab::FailButton(Device device) {
    Feedback(device,false);
    GetOS::reset_reboot();
}


