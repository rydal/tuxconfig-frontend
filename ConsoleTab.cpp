
#include <QApplication>
#include <QtDebug>
#include <QIcon>
#include <QMainWindow>
#include <QMenuBar>

#include "ConsoleTab.h"


 ConsoleTab::ConsoleTab(const QFileInfo &fileInfo,    QWidget *m_parent)
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

    success_label->setAlignment(Qt::AlignCenter);
    QFont f( "Arial", 16, QFont::Bold);
      success_label->setFont( f);

    works_button->setVisible(false);
    fails_button->setVisible(false);
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





   setLayout(mainLayout);
   connect(works_button, &QPushButton::clicked, [=] { works_result (); });
   connect(fails_button, &QPushButton::clicked, [=] { fails_result(); });


 }
void ConsoleTab::showButtons(vector<string> details, bool success) {

    fails_button->setVisible(true);


        works_button->setVisible(true);

    if (details.size() >= 2) {
    success_label->setText(details.at(2).c_str());

}
}

void ConsoleTab::works_result() {
    emit setTab(3);
    emit updateScreen();
    Feedback(current_device,true);

}
void ConsoleTab::fails_result() {
Feedback(current_device,false);
}

void ConsoleTab::updateDevice(Device device) {
    this->current_device = device;
}


