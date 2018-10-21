/*
 * RestoreTab.h
 *
 *  Created on: 4 Oct 2018
 *      Author: roberty
 */

#ifndef RESTORETAB_H_
#define RESTORETAB_H_


#include <QtGui>
#include <QtWidgets>
#include "GetHistory.h"
#include "RunConfig.h"
#include <vector>


class RestoreTab : public QWidget {
    Q_OBJECT
public:
    RestoreTab(const QFileInfo &fileInfo, QWidget *parent = 0);
    string DoRestore(Device device);
    void RestoreButton(Device device);

signals:
    void sendCommand(Device, string, vector<string>);
    void setTab(int);

};

#endif /* RESTORETAB_H_ */
