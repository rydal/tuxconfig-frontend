/*
 * QuestionBox.cpp
 *
 *  Created on: 7 Oct 2018
 *      Author: roberty
 */

#include "QuestionBox.h"


	// TODO Auto-generated constructor stub
	 QuestionBox::QuestionBox(string message) {
		 QString qmessage = QString::fromStdString(message);
		QMessageBox::information(
		    this,
		    tr("Tuxconfig"),
		    qmessage,QMessageBox::Cancel );	}

QuestionBox::~QuestionBox() {
	// TODO Auto-generated destructor stub
}

