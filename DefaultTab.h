/*
 * DefaultTab.h
 *
 *  Created on: 7 Oct 2018
 *      Author: roberty
 */

#ifndef DEFAULTTAB_H_
#define DEFAULTTAB_H_
#include <QApplication>
#include <QtWidgets>
#include <string>
#include <map>
#include <iterator>
#include "device.h"
#include "GetHistory.h"
#include "GetLocalDevices.h"
#include "GetRemoteConfig.h"
#include <set>
#include "RestoreTab.h"
#include "NotebookGUI.h"

class DefaultTab : public QWidget {
public:
	DefaultTab();
	virtual ~DefaultTab();
};

#endif /* DEFAULTTAB_H_ */
