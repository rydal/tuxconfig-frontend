/*: QDialog(parent) {
 * RestoreTab.cpp
 *
 *  Created on: 4 Oct 2018
 *      Author: roberty
 */

#include "RestoreTab.h"

RestoreTab::RestoreTab( QWidget *parent)

{
 mainLayout = new QVBoxLayout;

update("");

}

void RestoreTab::update(string message) {
    clearLayout(mainLayout, true);
    // TODO Auto-generated constructor stub
    std::map<string,Device> hashmap = GetHistory::getInstalledDevices();

         QPushButton *button = new QPushButton(QString::fromStdString("close"));

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
                                QPushButton *retry_button = new QPushButton(QString::fromStdString("Try next install"));

                                 installed_status->setText(QString::fromStdString(it->second.getStatus()));

                                m_Grid->addWidget(description);
                                m_Grid->addWidget(devicename);
                                m_Grid->addWidget(installed_status);
                                m_Grid->addWidget(restore_button1);
                                m_Grid->addWidget(retry_button);

                                bool installed = false;
                                if (it->second.getStatus() == "works" || it->second.getStatus() == "failed")
                                    installed = true;
                                    if (! installed) {
                                m_Grid->addWidget(success_button);
                                m_Grid->addWidget(fail_button);
                                }
                                    if (it->second.getStatus() != "works") {
                                        m_Grid->addWidget(retry_button);

                                    }

                                Device& tmp_device = it->second;
                                connect(restore_button1, &QPushButton::clicked, [=] { RestoreButton(tmp_device); });
                                connect(success_button, &QPushButton::clicked, [=] { SuccessButton(tmp_device); });
                                connect(fail_button, &QPushButton::clicked, [=] { FailButton(tmp_device); });
                                connect(retry_button, &QPushButton::clicked, [=] { RetryButton(tmp_device); });


                            mainLayout->addLayout(m_Grid);
                }
                QPushButton* updateButton = new QPushButton(QString::fromStdString("Rescan restore options"));
                mainLayout->addWidget(updateButton);
                connect(updateButton, &QPushButton::clicked, [=] { clearLayout(mainLayout,true) ;update("");});

                setLayout(mainLayout);

                 // Set layout in QWidget

}

void RestoreTab::RestoreButton(Device device) {

vector<string> parameters = RunConfig::restore(device);

    emit sendCommand(device, "restore", parameters );
    emit setTab(3);
}

void RestoreTab::SuccessButton(Device device) {
    Feedback(device,true);
    emit setTab(4);
    GetOS:: reset_reboot();
    }

void RestoreTab::FailButton(Device device) {
    Feedback(device,false);
    GetOS::reset_reboot();

}
void RestoreTab::RetryButton(Device device) {
    Device parsedDevice = GetRemoteConfig::GetConfiguration(device);
    vector<string> install = RunConfig::install(parsedDevice);
       emit setTab(3);

    emit sendCommand(parsedDevice, "install",install);

}

void RestoreTab::clearLayout(QLayout* layout, bool deleteWidgets)
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

