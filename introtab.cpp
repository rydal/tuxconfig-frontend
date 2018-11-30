#include "introtab.h"

introTab::introTab( QWidget *parent)
{
QMainWindow *mainWindow = new QMainWindow();

    mainLayout = new QVBoxLayout();
    image_label = new QLabel;
    QString url = QString::fromStdString("/usr/share/pixmaps/tux2.png");
    QPixmap img(url);
    image_label->setPixmap(img);
    label = new QLabel("Linux devices made easy");
    label->setAlignment(Qt::AlignCenter);
    image_label->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(image_label);
    mainLayout->addWidget(label);
    string description = "This utility automatically downloads and installs the software \n to make your devices work.  In cases where an install fails do \n not worry.  You can revert to your previous configuration.";

    QLabel *description_label = new QLabel(QString::fromStdString(description));
    description_label->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(description_label);


    QPushButton *runTabButton = new QPushButton("Get started");
    mainLayout->addWidget(runTabButton);


    QPushButton *restoreTabButton = new QPushButton("Restore previous configuration");
    mainLayout->addWidget(restoreTabButton);

    connect(restoreTabButton, &QPushButton::clicked, [=] { changeTab(2); });
    connect(runTabButton, &QPushButton::clicked, [=] { changeTab(1); });


    setLayout(mainLayout);

}

void introTab::changeTab(int tab) {
    emit setTab(tab);

}
