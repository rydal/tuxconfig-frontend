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
public:
    ContributorTab2(const QFileInfo &fileInfo, QWidget *parent = 0);

	virtual ~ContributorTab2();
	string* DownloadInfo(string owner_git_id);
	char* getAvatarImage(string url);


};

#endif /* MAINTAB_H_ */

