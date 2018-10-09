/*
 * Qu QApplication app(argc, argv);
	    QWidget window;
	    window.resize(320, 240);
	    window.show();
	    window.setWindowTitle(
	        QApplication::translate("toplevel", "Top-level widget"));
	    return app.exec();
 * estionBox.h
 *
 *  Created on: 7 Oct 2018
 *      Author: roberty
 */

#ifndef QUESTIONBOX_H_
#define QUESTIONBOX_H_
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
using namespace std;
class QuestionBox : public QMessageBox {
public:
	QuestionBox(string message);
	virtual ~QuestionBox();
};

#endif /* QUESTIONBOX_H_ */
