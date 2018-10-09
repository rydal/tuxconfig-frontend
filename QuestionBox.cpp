/*
 * QuestionBox.cpp
 *
 *  Created on: 7 Oct 2018
 *      Author: roberty
 */

#include "QuestionBox.h"


	// TODO Auto-generated constructor stub
	 QuestionBox::QuestionBox(string messsage) {
		QMessageBox::information(
		    this,
		    tr("Tuxconfig"),
		    tr("An information message."),QMessageBox::Cancel );	}

QuestionBox::~QuestionBox() {
	// TODO Auto-generated destructor stub
}

