/*
 * ContributorTab.cpp
 *
 *  Created on: 6 Oct 2018
 *      Author: roberty
 */

#include "ContributorTab2.h"
/**
  * @brief ContributorTab2::ContributorTab2
  * @param parent
  * Contributor tab, dispays information about the contributing devleoper.
  */
 ContributorTab2::ContributorTab2( QWidget *parent)
: QWidget(parent) {

    QMainWindow *mainWindow = new QMainWindow();

	// TODO Auto-generated constructor stub

        mainLayout = new QVBoxLayout();
        label = new QLabel("No contributor selected");
        label->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(label);
        setLayout(mainLayout);
        Device device;

}
 /**
  * @brief ContributorTab2::updateScreen
  * @param device
  * updates the contributor tab with information on a specific developer.
  * Information derived from device object.
  *
  */
 void ContributorTab2::updateScreen(Device device) {

clearLayout(mainLayout,true);

     details = DownloadInfo(device.getOwnerGitId());
     string image_location = getAvatarImage(details[4],device.getOwnerGitId());

     image_label = new QLabel;
     QString url = QString::fromStdString(image_location);
     QPixmap img(url);
     image_label->setPixmap(img);

    mainLayout->addWidget(image_label);


    "Contributor: " + details[0];

     QLabel *contributor_label = new QLabel;
     contributor_label->setText(QString::fromStdString("Contributor: " + details[0]));
     QLabel *bio_label = new QLabel;
     website_label = new QPushButton;
     email_label = new QPushButton;
     bio_label->setText(QString::fromStdString("Bio: " + details[1]));
     mainLayout->addWidget(contributor_label);
     mainLayout->addWidget(bio_label);


     string website_string = details[2];
     website_label->setText(QString::fromStdString(website_string));

     mainLayout->addWidget(website_label);



     string email_string = details[3];
     email_label->setText(QString::fromStdString(email_string));
     mainLayout->addWidget(email_label);
     connect(email_label, &QPushButton::clicked, [=] { on_description_linkActivated(); });
connect(website_label, &QPushButton::clicked, [=] { website_launch(); });

     mainLayout->setAlignment(Qt::AlignHCenter);

     reboot_label = new QLabel("Reboot required",  this);
     reboot_label->setVisible(false);
     reboot_button = new QPushButton(QString::fromStdString("Reboot Now?"));
     reboot_button->setVisible(false);
     mainLayout->addWidget(reboot_button);

     connect(reboot_button, &QPushButton::clicked, [=] { RebootMachine(); });

 }
 /**
  * @brief ContributorTab2::mousePressEvent
  * @param event
  * sends a message to GetOS to open contributors webpage when label clicked.
  */
 void ContributorTab2::mousePressEvent(QMouseEvent *event) {
GetOS::runWebpage(details[4]);
}
 /**
 * @brief ContributorTab2::DownloadInfo
 * @param owner_git_id
 * @return
 * returns a string array of contributor information downloaded from backend servlet.
 */
string* ContributorTab2::DownloadInfo(string owner_git_id) {
    details = new string[5];
	ostringstream os;
        string url = "https://linuxconf.feedthepeguin.org/live/getcontributor?owner_git_id=" + owner_git_id;
                curlpp::Easy easyhandle;
                easyhandle.setOpt(curlpp::options::Url(url));
                 easyhandle.setOpt(new curlpp::options::WriteStream(&os));
                easyhandle.perform();
        string str = os.str();
		Json::Value root;
		Json::Reader reader;

		bool parsingSuccessful = reader.parse(str, root);
		if (!parsingSuccessful) {
			cout << "error parsing";
			exit(1);
		}

		if (!root.isMember("Error")) {
			details[0] = root["name"].asString();
			details[1] = root["bio"].asString();
			details[2] = root["website"].asString();

			details[3] = root["email"].asString();
			details[4] = root["avatar_url"].asString();
		}
		return details;
}

/**
 * @brief ContributorTab2::getAvatarImage
 * @param url
 * @param owner_git_id
 * @return
 * downloads contributor's avatar image from github's url
 */
string ContributorTab2::getAvatarImage(string url, string owner_git_id) {
    HTTPDownloader downloader;
    return downloader.download(url,owner_git_id);

}
/**
 * @brief ConsoleTab::clearLayout
 * @param layout
 * @param deleteWidgets
 * Clears the layout for future method calls.
 */
void ContributorTab2::clearLayout(QLayout* layout, bool deleteWidgets = true)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}

void ContributorTab2::on_description_linkActivated()
{
    string mail_Address = "mailto:?to=";
    mail_Address +=  email_label->text().toUtf8().constData();
    GetOS::runEmail(mail_Address);
}

void ContributorTab2::website_launch()
{
    GetOS::runWebpage(website_label->text().toUtf8().constData());

}

void ContributorTab2::receiveReboot() {
    reboot_label->setVisible(true);
    reboot_button->setVisible(true);
}
void ContributorTab2::RebootMachine() {
    system("shutdown -r now");
}
