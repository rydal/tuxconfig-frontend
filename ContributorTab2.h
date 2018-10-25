/*
 * ContributorTab.h
 *
 *  Created on: 6 Oct 2018
 *      Author: roberty
 */
#ifndef MAINTAB_H_
#define MAINTAB_H_


#include <QApplication>
#include <QtWidgets>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <jsoncpp/json/json.h>
#include "HTTPDownloader.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <map>
#include <iterator>
#include "device.h"
#include "GetHistory.h"
#include "GetLocalDevices.h"
#include "GetRemoteConfig.h"
#include <set>
#include <stdio.h>
#include <stdlib.h>

#include "NotebookGUI.h"

class ContributorTab2  : public QWidget {
    Q_OBJECT
public:
    ContributorTab2(const QFileInfo &fileInfo, QWidget *parent = 0);
    string* DownloadInfo(string owner_git_id);
    string getAvatarImage(string url, string owner_git_id);

protected:
    QLabel *label;
    QLabel *image_label;
    QLabel *contributor_label;
    QLabel *website_label;
    QLabel *bio_label;
    QLabel *email_label;
    QLabel *reboot_label;
    QPushButton *reboot_button;
    QVBoxLayout *mainLayout;
    QMainWindow *mainWindow ;
    Device current_device;
    void mousePressEvent(QMouseEvent *event);
    string* details;
    void clearLayout(QLayout* layout, bool deleteWidgets );
public slots:
    void updateScreen(Device device);
    void on_description_linkActivated(const QString &link);
    void receiveReboot();

    void RebootMachine();


};

#endif /* MAINTAB_H_ */

