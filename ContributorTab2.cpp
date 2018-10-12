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
		QPushButton *button = new QPushButton("close");
		QVBoxLayout *mainLayout = new QVBoxLayout;

		string* details = DownloadInfo("stub");
		char* image = getAvatarImage(details[4]);
		QPixmap mpixmap;
			mpixmap.loadFromData(image,"JPG");
		QLabel *image_label = new QLabel;
		image_label->setPixmap(mpixmap);

		"Contributor: " + details[0];

		QLabel *contributor_label = new QLabel;
		contributor_label->setText(QString::fromStdString("Contributor: " + details[0]));
		QLabel *bio_label = new QLabel;
		QLabel *website_label = new QLabel;
		QLabel *email_label = new QLabel;
		bio_label->setText(QString::fromStdString("Bio: " + details[1]));
		mainLayout->addWidget(contributor_label);
		mainLayout->addWidget(bio_label);

		website_label->setText(QString::fromStdString("<a href=\"" + details[2] +  "\">Website</a>"));
		website_label->setTextFormat(Qt::RichText);
		website_label->setTextInteractionFlags(Qt::TextBrowserInteraction);
		website_label->setOpenExternalLinks(true);

		mainLayout->addWidget(website_label);

		email_label = new QLabel(this);
		email_label->setTextFormat(Qt::RichText);
		email_label->setText(QString::fromStdString("Email:href='" +  details[3] + "'>serge@essetee.be</a>"));
		email_label->setOpenExternalLinks(true);

		mainLayout->addWidget(email_label);
	    setLayout(mainLayout);



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


char* ContributorTab2::getAvatarImage(string url) {
    HTTPDownloader downloader;
    string returned_content = downloader.download(url);
    char char_array[returned_content.length()  + 1];
    strcpy(char_array,returned_content.c_str());
    return char_array;
}


