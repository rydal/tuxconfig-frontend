#include "introtab.h"

introTab::introTab(const QFileInfo &fileInfo, QWidget *parent)
{
QMainWindow *mainWindow = new QMainWindow();

    mainLayout = new QVBoxLayout();
    image_label = new QLabel;
    QString url = QString::fromStdString("/home/roberty/tuxconfig-qt/tux.png");
    QPixmap img(url);
    image_label->setPixmap(img);
    label = new QLabel("Making Linux Easy");
    label->setAlignment(Qt::AlignCenter);
    image_label->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(image_label);
    mainLayout->addWidget(label);
    string description = "This utility automatically downloads and installed the software \
                          to make your devices work.  In cases where an install fails do \
                          not worry.  You can revert to your previous configuration.";

    QLabel *description_label = new QLabel(description_label);
    mainLayout->addWidget(description_label);


    QPushButton *runTabButton = new QPushButton("Get started");
    mainLayout->addWidget(runTabButton);


    QPushButton *restoreTabButton = new QPushButton("Restore");
    mainLayout->addWidget(restoreTabButton);

    connect(restoreTabButton, &QPushButton::clicked, [=] { changeTab(1); });
    connect(runTabButton, &QPushButton::clicked, [=] { changeTab(0); });


    setLayout(mainLayout);

}

void introTab::changeTab(int tab) {
    emit setTab(tab);

}
