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
    /** Contirbutor tab.
     * @brief ContributorTab2
     * @param parent
     */
    ContributorTab2( QWidget *parent = 0);
    /** Downloads information of a contributor.
     * @brief DownloadInfo
     * @param owner_git_id contributor's user id on github.com
     * @return array { name, bio, website, email, avatar_url }
     */
    string* DownloadInfo(string owner_git_id);
    /** Gets the github avatar of a contibutor.
     * @brief getAvatarImage
     * @param url gtihub.com  url to get avatar from
     * @param owner_git_id
     * @return avatar url as string.
     */
    string getAvatarImage(string url, string owner_git_id);

protected:
    QLabel *label;
    QLabel *image_label;
    QLabel *contributor_label;
    QPushButton *website_label;
    QLabel *bio_label;
    QPushButton *email_label;
    QLabel *reboot_label;
    QPushButton *reboot_button;
    QVBoxLayout *mainLayout;
    QMainWindow *mainWindow ;
    Device current_device;
    void mousePressEvent(QMouseEvent *event);
    string* details;
    /** Clears the layout of the tab.
     * @brief ConsoleTab::clearLayout
     * @param layout layout to be removed.
     * @param deleteWidgets clear widgets as well as layout
     * Clears the layout for future method calls.
     */
    void clearLayout(QLayout* layout, bool deleteWidgets );
public slots:
    /** Updates the screen with the contributor details as found in the Device object.
     * @brief updateScreen
     * @param device
     */
    void updateScreen(Device device);
    /** sends a message to GetOS to send email to contributor when label clicked.
    * @brief ContributorTab2::on_description_linkActivated
     * @param link email link to be launched in mail client.
     */
    void on_description_linkActivated();
    /** Launches website via GetOS
     * @brief website_launched
     */
    void website_launch();
    ///sets reboot button and label to visible when method received.
    void receiveReboot();
    ///reboots machine.
    void RebootMachine();


};

#endif /* MAINTAB_H_ */

