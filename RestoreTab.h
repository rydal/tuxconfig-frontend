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
#include "CheckConnection.h"


class RestoreTab : public QWidget {
    Q_OBJECT
public:
    QLabel *already_installed;
    /** Constructor, tab to restore previous configurations.
     * @brief RestoreTab
     * @param parent
     */
    RestoreTab( QWidget *parent = 0);
    /**  Switches to console tab and restores configuration
     * @brief RestoreButton
     * @param device
     */
    void RestoreButton(Device device);
    /** fires method to feedback class, switches to contributor tab, removes run
     * on reboot flag.
     * @brief SuccessButton
     * @param device
     */
    void SuccessButton(Device device);
    /** fires method to feedback class, removes run
     * on reboot flag.
     * @brief FailButton
     * @param device
     */
    void RetryButton(Device device);
    /** Runs install again, process will pick up failed attempts.
     * @brief FailButton
     * @param device
     */

    void FailButton(Device device);
     QVBoxLayout *mainLayout;
     /** Clears layout when run multiple times.
      * @brief clearLayout
      * @param layout
      * @param deleteWidgets
      */
     void clearLayout(QLayout* layout, bool deleteWidgets);
     bool getLastInstall(Device device);


signals:
     /** Sends command to console tab.
     * @brief sendCommand
     */
    void sendCommand(Device, string, vector<string>);
    /**
     * @brief updateScreen
     */
    /** Updates contributor tab
     * @brief updateScreen
     */
    void updateScreen(void);
    /** Sets active tab by index.
     * @brief setTab
     */
    void setTab(int);

public slots:
    /** Redraws tab with new information where /var/lib/tuxconfig file has changed.
     * @brief update
     * @param message
     */
    void update(string message);
};

#endif /* RESTORETAB_H_ */
