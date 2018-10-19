/*
 * ContributorTab.cpp
 *
 *  Created on: 6 Oct 2018
 *      Author: roberty
 */

#include "ContributorTab2.h"

 ContributorTab2::ContributorTab2(const QFileInfo &fileInfo, QWidget *parent)
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

     label->setVisible(false);
     string* details = DownloadInfo(device.getOwnerGitId());
     string image_location = getAvatarImage(details[4],device.getOwnerGitId());

     image_label = new QLabel;
       cout<<"image location"<<image_location<<endl;
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

     connect(upgrade_button, &QLabel::clicked, [=] { GetOS::runWebpage(details[2]) });


     email_label->setOpenExternalLinks(true);
     string email_string = "<a href='mailto:" + details[3] + "'>My Email address.</a>";
     email_label->setText(QString::fromStdString(email_string));
     mainLayout->addWidget(email_label);


     mainLayout->addWidget(email_label);
     mainLayout->setAlignment(Qt::AlignHCenter);


 }


string* ContributorTab2::DownloadInfo(string owner_git_id) {
	string* details = new string[5];
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
