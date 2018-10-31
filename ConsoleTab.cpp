#include <QApplication>
#include <QtDebug>
#include <QIcon>
#include <QMainWindow>
#include <QMenuBar>
#include "ConsoleTab.h"


 ConsoleTab::ConsoleTab(    QWidget *m_parent)
 : parent(m_parent)
{

     mainLayout = new QGridLayout;
     console = new QTermWidget();
     console->setObjectName("console");
    QPushButton *m_button = new QPushButton("Close");
    console->actions();
    console->setColorScheme("GreenOnBlack");

   works_button = new QPushButton("Yes devie works", this);
   fails_button = new QPushButton("No device fails", this);
    success_label = new QLabel(" ");
    works_button->setObjectName("works_button");
    fails_button->setObjectName("fails_button");
    success_label->setObjectName("success_label");
    reboot_label = new QLabel("Reboot required",this);
    reboot_button = new QPushButton(QString::fromStdString("Reboot now?"));

    success_label->setAlignment(Qt::AlignCenter);
    QFont f( "Arial", 16, QFont::Bold);
      success_label->setFont( f);

    works_button->setVisible(false);
    fails_button->setVisible(false);
    reboot_label->setVisible(false);
    reboot_button->setVisible(false);
    QFont font = QApplication::font();
#ifdef Q_WS_MAC
    font.setFamily("Monaco");
#elif defined(Q_WS_QWS)
    font.setFamily("fixed");
#else
    font.setFamily("Monospace");
#endif
    font.setPointSize(12);

    console->setTerminalFont(font);

   // console->setColorScheme(COLOR_SCHEME_BLACK_ON_LIGHT_YELLOW);
    console->setScrollBarPosition(QTermWidget::ScrollBarRight);

    const auto arguments = QApplication::arguments();
    for (const QString& arg : arguments)
    {
        if (console->availableColorSchemes().contains(arg))
            console->setColorScheme(arg);
        if (console->availableKeyBindings().contains(arg))
            console->setKeyBindings(arg);
    }

    mainLayout->addWidget(console);

    mainLayout->addWidget(success_label);
    mainLayout->addWidget(works_button);
    mainLayout->addWidget(fails_button);
    mainLayout->addWidget(reboot_button);





   setLayout(mainLayout);
   connect(works_button, &QPushButton::clicked, [=] { works_result(); });
   connect(fails_button, &QPushButton::clicked, [=] { fails_result(); });

   connect(reboot_button, &QPushButton::clicked, [=] { RebootMachine(); });


 }
void ConsoleTab::showButtons(vector<string> details, bool success) {

    if (success) {
        works_button->setVisible(true);
        fails_button->setVisible(true);

    if (details.size() >= 3) {
    success_label->setText(details.at(2).c_str());

    string command_string = details.at(1) +" > /dev/null 2>&1 \r";
    if (details.size() >= 4) {
        if (details.at(3) == "true") {
            reboot_label->setVisible(true);
            reboot_button->setVisible(true);
        }

    }
    console->sendText(command_string.c_str());

    } else {
        success_label->setText("Command completed successfully");
    }
} else {
        success_label->setText("Command failed");
        emit refreshRestore("Install for device " + current_device.getDevicename() + " , " + current_device.getDescription() +" failed.");

    }



}

void ConsoleTab::works_result() {
    emit setTab(3);
    emit updateScreen();
    Feedback(current_device,true);
    GetOS::reset_reboot();
    works_button->setVisible(false);
    fails_button->setVisible(false);


}
void ConsoleTab::fails_result() {
Feedback(current_device,false);
GetOS::reset_reboot();
works_button->setVisible(false);
fails_button->setVisible(false);

}

void ConsoleTab::sendToConsole(Device device,string method, vector<string> parameters) {
    this->current_device = device;
    string command_string = parameters.at(0) +" \r";
    console->sendText(command_string.c_str());
}

void ConsoleTab::RebootMachine() {
    system("shutdown -h now");
}


