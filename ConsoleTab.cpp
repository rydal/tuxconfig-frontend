
#include <QApplication>
#include <QtDebug>
#include <QIcon>
#include <QMainWindow>
#include <QMenuBar>

#include "ConsoleTab.h"

 ConsoleTab::ConsoleTab(const QFileInfo &fileInfo,    QWidget *m_parent)
 : parent(m_parent)
{

		QVBoxLayout *mainLayout = new QVBoxLayout;
     console = new QTermWidget();
     console->setObjectName("console");
    QPushButton *m_button = new QPushButton("Close");
    console->actions();

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

    // info output
    qDebug() << "* INFO *************************";
    qDebug() << " availableKeyBindings:" << console->availableKeyBindings();
    qDebug() << " keyBindings:" << console->keyBindings();
    qDebug() << " availableColorSchemes:" << console->availableColorSchemes();
    qDebug() << "* INFO END *********************";

    // real startup
    QObject::connect(console, SIGNAL(finished()), mainLayout, SLOT(close()));


   setLayout(mainLayout);

   QObject::connect(m_button, SIGNAL(clicked()),this, SLOT(closeButton()));


}
void ConsoleTab::move_tabs(int index) {
    tabWidget->setCurrentIndex(index);

}

 void ConsoleTab::RunInstallConfig(Device device) {
console->sendText("hello");
}





