#############################################################################
# Makefile for building: tuxconfig
# Generated by qmake (3.0) (Qt 5.7.1)
# Project:  tuxconfig-qt.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt5/bin/qmake -o Makefile tuxconfig-qt.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -std=gnu++1y -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I. -isystem /usr/include/jsoncpp -isystem /usr/include/qtermwidget5 -isystem /usr/include/qtermwidget5 -isystem /usr/include/boost -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64
QMAKE         = /usr/lib/x86_64-linux-gnu/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = tuxconfig1.0.0
DISTDIR = /home/roberty/git/tuxconfig-qt/.tmp/tuxconfig1.0.0
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS) -L/usr/X11R6/lib64 -L/usr/include/boost -lboost_system -L/usr/include/qtermwidget5 -lqtermwidget5 -L/usr/local/include/curlpp -lcurlpp -L/usr/include/x86_64-linux-gnu/curl/ -lcurl -L/usr/include/jsoncpp -ljsoncpp -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = CheckConnection.cpp \
		ConsoleTab.cpp \
		ContributorTab2.cpp \
		RunConfigTab.cpp \
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
		RunConfig.cpp moc_ConsoleTab.cpp \
		moc_ContributorTab2.cpp \
		moc_RunConfigTab.cpp \
		moc_introtab.cpp \
		moc_NotebookGUI.cpp \
		moc_RestoreTab.cpp
OBJECTS       = CheckConnection.o \
		ConsoleTab.o \
		ContributorTab2.o \
		RunConfigTab.o \
		device.o \
		Feedback.o \
		GetHistory.o \
		GetLocalDevices.o \
		GetOS.o \
		GetRemoteConfig.o \
		HTTPDownloader.o \
		introtab.o \
		Linuxconf.o \
		NotebookGUI.o \
		QuestionBox.o \
		RestoreCmd.o \
		RestoreTab.o \
		RunConfig.o \
		moc_ConsoleTab.o \
		moc_ContributorTab2.o \
		moc_RunConfigTab.o \
		moc_introtab.o \
		moc_NotebookGUI.o \
		moc_RestoreTab.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		tuxconfig-qt.pro CheckConnection.h \
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
		RunConfig.h CheckConnection.cpp \
		ConsoleTab.cpp \
		ContributorTab2.cpp \
		RunConfigTab.cpp \
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
QMAKE_TARGET  = tuxconfig
DESTDIR       = 
TARGET        = tuxconfig


first: all
####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: tuxconfig-qt.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		tuxconfig-qt.pro \
		/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Gui.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Core.prl
	$(QMAKE) -o Makefile tuxconfig-qt.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
tuxconfig-qt.pro:
/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl:
/usr/lib/x86_64-linux-gnu/libQt5Gui.prl:
/usr/lib/x86_64-linux-gnu/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile tuxconfig-qt.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents CheckConnection.h compare.h ConsoleTab.h ContributorTab2.h RunConfigTab.h device.h Feedback.h GetHistory.h GetLocalDevices.h GetOS.h GetRemoteConfig.h HTTPDownloader.hpp introtab.h Linuxconf.h NotebookGUI.h QuestionBox.h RestoreCmd.h RestoreTab.h RunConfig.h $(DISTDIR)/
	$(COPY_FILE) --parents CheckConnection.cpp ConsoleTab.cpp ContributorTab2.cpp RunConfigTab.cpp device.cpp Feedback.cpp GetHistory.cpp GetLocalDevices.cpp GetOS.cpp GetRemoteConfig.cpp HTTPDownloader.cpp introtab.cpp Linuxconf.cpp NotebookGUI.cpp QuestionBox.cpp RestoreCmd.cpp RestoreTab.cpp RunConfig.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: moc_ConsoleTab.cpp moc_ContributorTab2.cpp moc_RunConfigTab.cpp moc_introtab.cpp moc_NotebookGUI.cpp moc_RestoreTab.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_ConsoleTab.cpp moc_ContributorTab2.cpp moc_RunConfigTab.cpp moc_introtab.cpp moc_NotebookGUI.cpp moc_RestoreTab.cpp
moc_ConsoleTab.cpp: NotebookGUI.h \
		device.h \
		GetOS.h \
		GetHistory.h \
		GetRemoteConfig.h \
		GetLocalDevices.h \
		compare.h \
		RestoreTab.h \
		RunConfig.h \
		Feedback.h \
		ConsoleTab.h \
		ContributorTab2.h \
		HTTPDownloader.hpp \
		RunConfigTab.h \
		introtab.h \
		ConsoleTab.h \
		/usr/lib/x86_64-linux-gnu/qt5/bin/moc
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/roberty/git/tuxconfig-qt -I/home/roberty/git/tuxconfig-qt -I/usr/include/jsoncpp -I/usr/include/qtermwidget5 -I/usr/include/qtermwidget5 -I/usr/include/boost -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/6 -I/usr/include/x86_64-linux-gnu/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/x86_64-linux-gnu/6/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/6/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include ConsoleTab.h -o moc_ConsoleTab.cpp

moc_ContributorTab2.cpp: HTTPDownloader.hpp \
		device.h \
		GetOS.h \
		GetHistory.h \
		GetRemoteConfig.h \
		GetLocalDevices.h \
		compare.h \
		NotebookGUI.h \
		RestoreTab.h \
		RunConfig.h \
		Feedback.h \
		ConsoleTab.h \
		ContributorTab2.h \
		RunConfigTab.h \
		introtab.h \
		ContributorTab2.h \
		/usr/lib/x86_64-linux-gnu/qt5/bin/moc
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/roberty/git/tuxconfig-qt -I/home/roberty/git/tuxconfig-qt -I/usr/include/jsoncpp -I/usr/include/qtermwidget5 -I/usr/include/qtermwidget5 -I/usr/include/boost -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/6 -I/usr/include/x86_64-linux-gnu/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/x86_64-linux-gnu/6/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/6/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include ContributorTab2.h -o moc_ContributorTab2.cpp

moc_RunConfigTab.cpp: device.h \
		GetOS.h \
		GetLocalDevices.h \
		compare.h \
		GetRemoteConfig.h \
		NotebookGUI.h \
		GetHistory.h \
		RestoreTab.h \
		RunConfig.h \
		Feedback.h \
		ConsoleTab.h \
		ContributorTab2.h \
		HTTPDownloader.hpp \
		RunConfigTab.h \
		introtab.h \
		RunConfigTab.h \
		/usr/lib/x86_64-linux-gnu/qt5/bin/moc
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/roberty/git/tuxconfig-qt -I/home/roberty/git/tuxconfig-qt -I/usr/include/jsoncpp -I/usr/include/qtermwidget5 -I/usr/include/qtermwidget5 -I/usr/include/boost -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/6 -I/usr/include/x86_64-linux-gnu/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/x86_64-linux-gnu/6/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/6/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include RunConfigTab.h -o moc_RunConfigTab.cpp

moc_introtab.cpp: HTTPDownloader.hpp \
		device.h \
		GetOS.h \
		GetHistory.h \
		GetRemoteConfig.h \
		GetLocalDevices.h \
		compare.h \
		NotebookGUI.h \
		RestoreTab.h \
		RunConfig.h \
		Feedback.h \
		ConsoleTab.h \
		ContributorTab2.h \
		RunConfigTab.h \
		introtab.h \
		introtab.h \
		/usr/lib/x86_64-linux-gnu/qt5/bin/moc
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/roberty/git/tuxconfig-qt -I/home/roberty/git/tuxconfig-qt -I/usr/include/jsoncpp -I/usr/include/qtermwidget5 -I/usr/include/qtermwidget5 -I/usr/include/boost -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/6 -I/usr/include/x86_64-linux-gnu/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/x86_64-linux-gnu/6/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/6/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include introtab.h -o moc_introtab.cpp

moc_NotebookGUI.cpp: device.h \
		GetOS.h \
		GetHistory.h \
		GetRemoteConfig.h \
		GetLocalDevices.h \
		compare.h \
		RestoreTab.h \
		RunConfig.h \
		Feedback.h \
		ConsoleTab.h \
		NotebookGUI.h \
		ContributorTab2.h \
		HTTPDownloader.hpp \
		RunConfigTab.h \
		introtab.h \
		NotebookGUI.h \
		/usr/lib/x86_64-linux-gnu/qt5/bin/moc
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/roberty/git/tuxconfig-qt -I/home/roberty/git/tuxconfig-qt -I/usr/include/jsoncpp -I/usr/include/qtermwidget5 -I/usr/include/qtermwidget5 -I/usr/include/boost -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/6 -I/usr/include/x86_64-linux-gnu/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/x86_64-linux-gnu/6/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/6/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include NotebookGUI.h -o moc_NotebookGUI.cpp

moc_RestoreTab.cpp: GetHistory.h \
		device.h \
		GetOS.h \
		GetRemoteConfig.h \
		RunConfig.h \
		Feedback.h \
		RestoreTab.h \
		/usr/lib/x86_64-linux-gnu/qt5/bin/moc
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/roberty/git/tuxconfig-qt -I/home/roberty/git/tuxconfig-qt -I/usr/include/jsoncpp -I/usr/include/qtermwidget5 -I/usr/include/qtermwidget5 -I/usr/include/boost -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/6 -I/usr/include/x86_64-linux-gnu/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/x86_64-linux-gnu/6/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/6/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include RestoreTab.h -o moc_RestoreTab.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

CheckConnection.o: CheckConnection.cpp CheckConnection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CheckConnection.o CheckConnection.cpp

ConsoleTab.o: ConsoleTab.cpp ConsoleTab.h \
		NotebookGUI.h \
		device.h \
		GetOS.h \
		GetHistory.h \
		GetRemoteConfig.h \
		GetLocalDevices.h \
		compare.h \
		RestoreTab.h \
		RunConfig.h \
		Feedback.h \
		ContributorTab2.h \
		HTTPDownloader.hpp \
		RunConfigTab.h \
		introtab.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ConsoleTab.o ConsoleTab.cpp

ContributorTab2.o: ContributorTab2.cpp ContributorTab2.h \
		HTTPDownloader.hpp \
		device.h \
		GetOS.h \
		GetHistory.h \
		GetRemoteConfig.h \
		GetLocalDevices.h \
		compare.h \
		NotebookGUI.h \
		RestoreTab.h \
		RunConfig.h \
		Feedback.h \
		ConsoleTab.h \
		RunConfigTab.h \
		introtab.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ContributorTab2.o ContributorTab2.cpp

RunConfigTab.o: RunConfigTab.cpp RunConfigTab.h \
		device.h \
		GetOS.h \
		GetLocalDevices.h \
		compare.h \
		GetRemoteConfig.h \
		NotebookGUI.h \
		GetHistory.h \
		RestoreTab.h \
		RunConfig.h \
		Feedback.h \
		ConsoleTab.h \
		ContributorTab2.h \
		HTTPDownloader.hpp \
		introtab.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o RunConfigTab.o RunConfigTab.cpp

device.o: device.cpp device.h \
		GetOS.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o device.o device.cpp

Feedback.o: Feedback.cpp Feedback.h \
		device.h \
		GetOS.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Feedback.o Feedback.cpp

GetHistory.o: GetHistory.cpp GetHistory.h \
		device.h \
		GetOS.h \
		GetRemoteConfig.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GetHistory.o GetHistory.cpp

GetLocalDevices.o: GetLocalDevices.cpp GetLocalDevices.h \
		compare.h \
		device.h \
		GetOS.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GetLocalDevices.o GetLocalDevices.cpp

GetOS.o: GetOS.cpp GetOS.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GetOS.o GetOS.cpp

GetRemoteConfig.o: GetRemoteConfig.cpp GetRemoteConfig.h \
		device.h \
		GetOS.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GetRemoteConfig.o GetRemoteConfig.cpp

HTTPDownloader.o: HTTPDownloader.cpp HTTPDownloader.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o HTTPDownloader.o HTTPDownloader.cpp

introtab.o: introtab.cpp introtab.h \
		HTTPDownloader.hpp \
		device.h \
		GetOS.h \
		GetHistory.h \
		GetRemoteConfig.h \
		GetLocalDevices.h \
		compare.h \
		NotebookGUI.h \
		RestoreTab.h \
		RunConfig.h \
		Feedback.h \
		ConsoleTab.h \
		ContributorTab2.h \
		RunConfigTab.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o introtab.o introtab.cpp

Linuxconf.o: Linuxconf.cpp Linuxconf.h \
		CheckConnection.h \
		GetOS.h \
		RunConfig.h \
		device.h \
		GetRemoteConfig.h \
		NotebookGUI.h \
		GetHistory.h \
		GetLocalDevices.h \
		compare.h \
		RestoreTab.h \
		Feedback.h \
		ConsoleTab.h \
		ContributorTab2.h \
		HTTPDownloader.hpp \
		RunConfigTab.h \
		introtab.h \
		RestoreCmd.h \
		QuestionBox.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Linuxconf.o Linuxconf.cpp

NotebookGUI.o: NotebookGUI.cpp NotebookGUI.h \
		device.h \
		GetOS.h \
		GetHistory.h \
		GetRemoteConfig.h \
		GetLocalDevices.h \
		compare.h \
		RestoreTab.h \
		RunConfig.h \
		Feedback.h \
		ConsoleTab.h \
		ContributorTab2.h \
		HTTPDownloader.hpp \
		RunConfigTab.h \
		introtab.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o NotebookGUI.o NotebookGUI.cpp

QuestionBox.o: QuestionBox.cpp QuestionBox.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o QuestionBox.o QuestionBox.cpp

RestoreCmd.o: RestoreCmd.cpp RestoreCmd.h \
		device.h \
		GetOS.h \
		GetRemoteConfig.h \
		GetHistory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o RestoreCmd.o RestoreCmd.cpp

RestoreTab.o: RestoreTab.cpp RestoreTab.h \
		GetHistory.h \
		device.h \
		GetOS.h \
		GetRemoteConfig.h \
		RunConfig.h \
		Feedback.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o RestoreTab.o RestoreTab.cpp

RunConfig.o: RunConfig.cpp RunConfig.h \
		device.h \
		GetOS.h \
		GetRemoteConfig.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o RunConfig.o RunConfig.cpp

moc_ConsoleTab.o: moc_ConsoleTab.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ConsoleTab.o moc_ConsoleTab.cpp

moc_ContributorTab2.o: moc_ContributorTab2.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ContributorTab2.o moc_ContributorTab2.cpp

moc_RunConfigTab.o: moc_RunConfigTab.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_RunConfigTab.o moc_RunConfigTab.cpp

moc_introtab.o: moc_introtab.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_introtab.o moc_introtab.cpp

moc_NotebookGUI.o: moc_NotebookGUI.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_NotebookGUI.o moc_NotebookGUI.cpp

moc_RestoreTab.o: moc_RestoreTab.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_RestoreTab.o moc_RestoreTab.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

