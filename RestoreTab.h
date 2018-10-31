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
#include "Feedback.h"
#include "GetOS.h"


class RestoreTab : public QWidget {
    Q_OBJECT
public:
    RestoreTab( QWidget *parent = 0);
    string DoRestore(Device device);
    void RestoreButton(Device device);
    void SuccessButton(Device device);
    void FailButton(Device device);
     QVBoxLayout *mainLayout;
     void clearLayout(QLayout* layout, bool deleteWidgets);


signals:
    void sendCommand(Device, string, vector<string>);
    void updateScreen(void);
    void setTab(int);

public slots:
    void update(string message);
};

#endif /* RESTORETAB_H_ */
