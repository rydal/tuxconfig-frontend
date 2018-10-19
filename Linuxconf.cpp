#include "Linuxconf.h"


namespace
{
std::function<void(int)> shutdown_handler;
void signal_handler(int signal) { shutdown_handler(signal); }
std::function<void(int)> shutdown_handler1;

void signal_handler1(int signal) { shutdown_handler(signal); }

}

int main(int argc, char *argv[]) {
	bool is_gui_present = GetOS::is_gui_present();

	//check root.
	if (getuid() != 0) {
		if (is_gui_present) {
			 QApplication app(argc, argv);
				    QuestionBox window("Not running as root, use su or sudo.");
				    return app.exec();

			//Shows the window and returns when it is closed.
		    } else {
			std::cout << "Not root user, exiting";
			exit(1);

		}
	}

	if (argc == 2) {
	if (strcmp(argv[1], "recover") == 0) {
		map <string, Device> installed_devices = GetHistory::getInstalledDevices();
        if (is_gui_present) {
            QApplication app(argc, argv);

            NotebookGUI gui("Tuxconfig");
            gui.show();
            gui.changeTab(1);
            return app.exec();

	}   else {
            RestoreGUI::CommandLineInstall(installed_devices);
            exit(1);
	}
	}
	}
	CheckConnection connchk = CheckConnection();
	if (connchk.CheckNetwork() == false) {
		 QApplication app(argc, argv);
			QuestionBox window(
					"No internet connection\n consider tethering with a mobile phone\n or plug into a network socket");
			    return app.exec();
        exit(1);

		//Shows the window and returns when it is closed.

	};

    const int dir_err = system("mkdir ~/.config/tuxconfig >  /dev/null 2>&1 ");
	if (-1 == dir_err) {
	    QApplication app(argc, argv);
		QuestionBox window("Can't create config directory ~/.config/tuxconfig");

		//Shows the window and returns when it is closed.
	    return app.exec();

		exit(1);
	}
    const int dir_err2 = system("mkdir /var/lib/tuxconfig >  /dev/null 2>&1 ");
	if (-1 == dir_err2) {
	    QApplication app(argc, argv);
		QuestionBox window("Can't create library directory /var/lib/tuxconfig");

		//Shows the window and returns when it is closed.
	    return app.exec();
		exit(1);
	}
    const int dir_err3 = system("mkdir /var/log/tuxconfig >  /dev/null 2>&1 ");
    if (-1 == dir_err3) {
        QApplication app(argc, argv);
        QuestionBox window("Can't create log directory /var/log/tuxconfig");

        //Shows the window and returns when it is closed.
        return app.exec();
        exit(1);
    }
    QApplication app(argc, argv);



    NotebookGUI gui("Tuxconfig");


    gui.show();
    std::signal(SIGUSR1, signal_handler);
    shutdown_handler = [&](int signal) {
        gui.showResultButtons();

      };



    return app.exec();



}

void LinuxConf::on_button_clicked(std::string command, Device& device) {
	if (command == "install") {
		RunConfig::install(device);
	}
	if (command == "uninstall") {

		RunConfig::uninstall(device);
	}
	if (command == "upgrade") {
		RunConfig::upgrade(device);
	}
	if (command == "restore") {
		RunConfig::install(device);
	}
}

