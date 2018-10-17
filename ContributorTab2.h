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
    QVBoxLayout *mainLayout;
    QMainWindow *mainWindow ;

public slots:
    void updateScreen(Device);

};

#endif /* MAINTAB_H_ */

