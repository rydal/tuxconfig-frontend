/*
 * DefaultTab.h
 *
 *  Created on: 7 Oct 2018
 *      Author: roberty
 */


#include <QtGui>
#include <QtWidgets>
#include <string>
#include <map>
#include <iterator>
#include "device.h"
#include "GetLocalDevices.h"
#include "GetRemoteConfig.h"


class QDialogButtonBox;
 class QFileInfo;
 class QTabWidget;


 class GeneralTab : public QWidget
 {

 public:
     GeneralTab(const QFileInfo &fileInfo, QWidget *parent = 0);
 };


