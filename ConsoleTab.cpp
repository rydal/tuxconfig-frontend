
#include <QApplication>
#include <QtDebug>
#include <QIcon>
#include <QMainWindow>
#include <QMenuBar>

#include "ConsoleTab.h"

ConsoleTab::ConsoleTab()
{

    QIcon::setThemeName("oxygen");
    QMainWindow *mainWindow = new QMainWindow();

    QTermWidget *console = new QTermWidget();
    console->actions();
    QMenuBar *menuBar = new QMenuBar(mainWindow);
    QMenu *actionsMenu = new QMenu("Actions", menuBar);
    menuBar->addMenu(actionsMenu);
    actionsMenu->addAction("Find..", console, SLOT(toggleShowSearchBar()), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_F));
    mainWindow->setMenuBar(menuBar);

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

    mainWindow->setCentralWidget(console);
    mainWindow->resize(600, 400);

    // info output
    qDebug() << "* INFO *************************";
    qDebug() << " availableKeyBindings:" << console->availableKeyBindings();
    qDebug() << " keyBindings:" << console->keyBindings();
    qDebug() << " availableColorSchemes:" << console->availableColorSchemes();
    qDebug() << "* INFO END *********************";

    // real startup
    QObject::connect(console, SIGNAL(finished()), mainWindow, SLOT(close()));

    console->sendText("ls");

    mainWindow->show();

}

ConsoleTab::~ConsoleTab() {

}

