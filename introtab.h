#ifndef INTROTAB_H
#define INTROTAB_H




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
class introTab : public QWidget
{
    Q_OBJECT
public:
    introTab( QWidget *parent = 0);
    QLabel *label;
    QLabel *image_label;
    QLabel *description_label;
    QVBoxLayout *mainLayout;
    QMainWindow *mainWindow ;
    void changeTab(int tab);
signals:
    void setTab(int);

};

#endif // INTROTAB_H
