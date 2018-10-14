
#include <QApplication>
#include <QtDebug>
#include <QIcon>
#include <QMainWindow>
#include <QMenuBar>

#include "ConsoleTab.h"

Device current_device;

 ConsoleTab::ConsoleTab(const QFileInfo &fileInfo,    QWidget *m_parent)
 : parent(m_parent)
{

     mainLayout = new QVBoxLayout;
     console = new QTermWidget();
     console->setObjectName("console");
    QPushButton *m_button = new QPushButton("Close");
    console->actions();
    console->setColorScheme("GreenOnBlack");

   works_button = new QPushButton("Yes devie works", this);
    fails_button = new QPushButton("No device fails", this);

    works_button->setObjectName("works_button");
    works_button->setObjectName("fails_button");
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
    mainLayout->addWidget(works_button);
    mainLayout->addWidget(fails_button);

       QObject::connect(console, SIGNAL(finished()), mainLayout, SLOT(close()));


   setLayout(mainLayout);

   QObject::connect(m_button, SIGNAL(clicked()),this, SLOT(closeButton()));




 }



 void ConsoleTab::setDevice(Device device) {
     current_device = device;
 }
