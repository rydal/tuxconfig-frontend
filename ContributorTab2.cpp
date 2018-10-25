/*
 * ContributorTab.cpp
 *
 *  Created on: 6 Oct 2018
 *      Author: roberty
 */

#include "ContributorTab2.h"

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
     QLabel *website_label = new QLabel;
     QLabel *email_label = new QLabel;
     bio_label->setText(QString::fromStdString("Bio: " + details[1]));
     mainLayout->addWidget(contributor_label);
     mainLayout->addWidget(bio_label);


     website_label->setOpenExternalLinks(true);
     string website_string = "<a href='"+ details[2] + "'>Visit my page.</a>";
     website_label->setText(QString::fromStdString(website_string));

     mainLayout->addWidget(website_label);

     mainLayout->addWidget(website_label);



     email_label->setOpenExternalLinks(false);
     string email_string = "<a href='mailto:" + details[3] + "'>My Email address.</a>";
     email_label->setText(QString::fromStdString(email_string));
     mainLayout->addWidget(email_label);

     connect(email_label, &QLabel::linkActivated, [=] { on_description_linkActivated(QString::fromStdString(details[3])); });


     mainLayout->addWidget(email_label);
     mainLayout->setAlignment(Qt::AlignHCenter);

     reboot_label = new QLabel("Reboot required",  this);
     reboot_label->setVisible(false);
     reboot_button = new QPushButton(QString::fromStdString("Reboot Now?"));
     reboot_button->setVisible(false);
     mainLayout->addWidget(reboot_button);

     connect(reboot_button, &QPushButton::clicked, [=] { RebootMachine(); });

 }
 void ContributorTab2::mousePressEvent(QMouseEvent *event) {
GetOS::runWebpage(details[4]);
}
string* ContributorTab2::DownloadInfo(string owner_git_id) {
    details = new string[5];
	ostringstream os;
		string url = "https://linuxconf.feedthepenguin.org/hehe/getcontributor?owner_git_id=" + owner_git_id;
		os << curlpp::options::Url(url);
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


string ContributorTab2::getAvatarImage(string url, string owner_git_id) {
    HTTPDownloader downloader;
    return downloader.download(url,owner_git_id);

}

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

void ContributorTab2::on_description_linkActivated(const QString &link)
{
    std::string utf8_text = link.toUtf8().constData();

  GetOS::runEmail(utf8_text);
}

void ContributorTab2::receiveReboot() {
    reboot_label->setVisible(true);
    reboot_button->setVisible(true);
}

void ContributorTab2::RebootMachine() {
    system("shutdown -r now");
}
