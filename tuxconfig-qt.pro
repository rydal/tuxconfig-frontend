######################################################################
# Automatically generated by qmake (3.0) Thu Oct 11 15:12:08 2018
######################################################################

TEMPLATE = app
TARGET = tuxconfig
INCLUDEPATH += .\
	/usr/include/jsoncpp \
	/usr/include/qtermwidget5 \
	/usr/include/qtermwidget5 \
	/usr/include/boost
CONFIG += c++11


# Input
HEADERS += CheckConnection.h \
           compare.h \
           ConsoleTab.h \
           ContributorTab2.h \
           RunConfigTab.h \
           device.h \
           Feedback.h \
           GetHistory.h \
           GetLocalDevices.h \
           GetOS.h \
           GetRemoteConfig.h \
           HTTPDownloader.hpp \
	   introtab.h \
           Linuxconf.h \
           NotebookGUI.h \
           QuestionBox.h \
           RestoreCmd.h \
           RestoreTab.h \
           RunConfig.h
SOURCES += CheckConnection.cpp \
           ConsoleTab.cpp \
           ContributorTab2.cpp \
           RunconfigTab.cpp \
           device.cpp \
           Feedback.cpp \
           GetHistory.cpp \
           GetLocalDevices.cpp \
           GetOS.cpp \
           GetRemoteConfig.cpp \
           HTTPDownloader.cpp \
	   introtab.cpp \
           Linuxconf.cpp \
           NotebookGUI.cpp \
           QuestionBox.cpp \
           RestoreCmd.cpp \
           RestoreTab.cpp \
           RunConfig.cpp

	   QT += gui
	   QT += widgets

LIBS += -L"/usr/include/boost" -lboost_system \
	-L"/usr/include/qtermwidget5" -lqtermwidget5 \ 
	-L"/usr/local/include/curlpp" -lcurlpp \
	-L"/usr/include/x86_64-linux-gnu/curl/" -lcurl \	
	-L"/usr/include/jsoncpp" -ljsoncpp

CONFIG += c++14
