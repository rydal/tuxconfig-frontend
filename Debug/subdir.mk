################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CheckConnection.cpp \
../ConsoleTab.cpp \
../ContributorTab2.cpp \
../Feedback.cpp \
../GeneralTab.cpp \
../GetHistory.cpp \
../GetLocalDevices.cpp \
../GetOS.cpp \
../GetRemoteConfig.cpp \
../HTTPDownloader.cpp \
../Linuxconf.cpp \
../NotebookGUI.cpp \
../QuestionBox.cpp \
../RestoreGUI.cpp \
../RestoreTab.cpp \
../RunConfig.cpp \
../device.cpp 

O_SRCS += \
../CheckConnection.o \
../ConsoleTab.o \
../ContributorTab2.o \
../DefaultTab.o \
../Feedback.o \
../GetHistory.o \
../GetLocalDevices.o \
../GetOS.o \
../GetRemoteConfig.o \
../HTTPDownloader.o \
../Linuxconf.o \
../NotebookGUI.o \
../QuestionBox.o \
../RestoreGUI.o \
../RestoreTab.o \
../RunConfig.o \
../device.o \
../moc_ConsoleTab.o 

OBJS += \
./CheckConnection.o \
./ConsoleTab.o \
./ContributorTab2.o \
./Feedback.o \
./GeneralTab.o \
./GetHistory.o \
./GetLocalDevices.o \
./GetOS.o \
./GetRemoteConfig.o \
./HTTPDownloader.o \
./Linuxconf.o \
./NotebookGUI.o \
./QuestionBox.o \
./RestoreGUI.o \
./RestoreTab.o \
./RunConfig.o \
./device.o 

CPP_DEPS += \
./CheckConnection.d \
./ConsoleTab.d \
./ContributorTab2.d \
./Feedback.d \
./GeneralTab.d \
./GetHistory.d \
./GetLocalDevices.d \
./GetOS.d \
./GetRemoteConfig.d \
./HTTPDownloader.d \
./Linuxconf.d \
./NotebookGUI.d \
./QuestionBox.d \
./RestoreGUI.d \
./RestoreTab.d \
./RunConfig.d \
./device.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu -I/usr/include/jsoncpp -I/usr/include/qtermwidget5 -I/usr/include/x86_64-linux-gnu/qt5/QtXml -I/usr/include/boost -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


