/*
 * RunConfig.cpp
 *
 *  Created on: 3 Sep 2018
 *      Author: roberty
 */

#include "RunConfig.h"

int result;
string distribution_name;
string arch;
string test_result;
RunConfig::RunConfig()

{

	GetOS os;
	string* the_os = os.getLocalMchineDistro();
	distribution_name = std::string(the_os[0]);
	arch = std::string(the_os[2]);

}

RunConfig::~RunConfig() {
	// TODO Auto-generated destructor stub
}

bool RunConfig::uninstall(Device& device) {

	string runfile = "#!/bin/bash\n";
	runfile += "set -x \n";
	runfile += "set -e \n";
	runfile += "tar -cvpf /var/lib/tuxconfig/lib_backup-" + device.getDeviceid()
			+ "-uninstall.tar /lib /etc/modules* \n";

	runfile += "modprobe -r " + device.getModulename() + "\n";
	runfile += "echo blacklist " + device.getModulename()
			+ " >> /etc/modprobe.d/blacklist.conf \n";
	runfile += "echo uninstalled " + device.getModulename()
			+ " >> /root/.config/tuxconfig/uninstalled";
	string tuxconfig_config_name = "/usr/src/tuxconfig-uninstall-"
			+ device.getDeviceid();
	std::ofstream out(tuxconfig_config_name);
	out << runfile;
	out.close();
	string tuxconfig_chmod_command = "chmod u+x " + tuxconfig_config_name;
	system(tuxconfig_chmod_command.c_str());
	string tuxconfig_config_run = "/bin/bash " + tuxconfig_config_name;
	int status = system(tuxconfig_config_run.c_str());

	if (status == 0) {



	} else {

	}
	return false;
}

bool RunConfig::install(Device device) {
	string runfile = "#!/bin/bash \n";
	runfile += "set -e \n";
	runfile += "set -x \n";

	runfile += "touch /root/.config/tuxconfig/history \n";

	//backup /lib folder

	string filedir = device.getGitUrl();
	boost::replace_all(filedir, "https://github.com/", "");
	boost::replace_all(filedir, ".git", "");
	runfile += "tar -cvpf /var/lib/tuxconfig/lib_backup-" + device.getDeviceid()
			+ "-install.tar /lib /etc/modules* \n";

	runfile += "URL=" + device.getGitUrl() + " \n";
	runfile += "COMMIT=" + device.getCommit() + " \n";

	runfile += "rm -rf /usr/src/" + filedir + " \n";
	runfile += "mkdir -p " + filedir + "\n";
	runfile += "git clone $URL /usr/src/" + filedir + " \n";
	runfile += "echo git repository downloaded \n";
	runfile += "wait\n";
	runfile += "cd /usr/src/" + filedir + " \n";
	runfile += "git checkout $COMMIT\n";
	runfile += "echo commit checked out\n";

	string tuxconfig_file = "/usr/src/" + filedir + "/tuxconfig";

	runfile += ". " + tuxconfig_file + "\n";
//install dependencies;
	runfile += "eval $dependencies \n";
	runfile += " if [ -z \"${dependencies+x}\" ] ; then \n";
	runfile  +=  "echo \"" + device.getDeviceid() + "," + device.getDescription() + ","	+ to_string(device.getVoteDifference()) + ",installed \" >> /root/.config/tuxconfig/history  ";
runfile += "fi \n";

	runfile += "if [ -f Makefile ] ; then \n";
	runfile += "echo \"installed dependencies\" \n";
//Build module
	runfile += "make\n";
	runfile += "echo \"built source code\" \n";
//Install module
	runfile += "make install\n";
	runfile += "echo \"installed source code\" \n";
//Insert module
	runfile += "modprobe -v $tuxconfig_module \n";
	runfile += "echo \"inserted module into kernel\" \n";
	runfile  +=  "echo \"" + device.getDeviceid() + "," + device.getDescription() + ","	+ to_string(device.getVoteDifference()) + ",installed \" >> /root/.config/tuxconfig/history  ";
	runfile += "fi \n";
	runfile += "echo all looks ok \n";
	runfile += "read finish \n";
	boost::replace_all(filedir, "/", "-");
	string tuxconfig_run_name = "/usr/src/tuxconfig-" + filedir;
	std::ofstream out(tuxconfig_run_name);
	out << runfile;
	out.close();
	string tuxconfig_chmod_command = "chmod u+x " + tuxconfig_run_name;
	system(tuxconfig_chmod_command.c_str());
	string tuxconfig_run_command = "xterm -e " + tuxconfig_run_name
			+ "| tee > /var/lib/tuxconfig/log_install-" + filedir;

	int result = WEXITSTATUS(system(tuxconfig_run_command.c_str()));

	if (result != 0) {

		string send_failure = "echo '" + device.getDeviceid() + "," + device.getDescription() + ","	+ to_string(device.getVoteDifference()) + ",failed' >> /root/.config/tuxconfig/history";
		system(send_failure.c_str());
		exit(1);
	}

	string line;
	ifstream myfile;
	myfile.open(tuxconfig_file);
	string test_program;
	string test_message;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			if (line.find("test_program=") == 0) {
				boost::replace_all(line, "test_program=", "");
				boost::trim(line);
				test_program = line + " &";

			}
			if (line.find("test_message=") == 0) {
				boost::replace_all(line, "test_message=", "");
				boost::trim(line);
				test_message = line;

			}

		}

	}
	myfile.close();

	system(test_program.c_str());
	//FIXME Message dialog wtith contributor details.

	//Shows the window and returns when it is closed.
	if (test_result == "yes") {
		string send_success = "echo \"" + device.getDeviceid() + "," + device.getDescription() + ","	+ to_string(device.getVoteDifference()) + ",works \" >> /root/.config/tuxconfig/history  ";
		system(send_success.c_str());
		return true;
	} else {
		string send_failed = "echo \"" + device.getDeviceid() + "," + device.getDescription() + ","	+ to_string(device.getVoteDifference()) + ",failed  \" >> /root/.config/tuxconfig/history  ";
				system(send_failed.c_str());
	}

}

bool RunConfig::upgrade(Device device) {
	GetRemoteConfig remote_config_class;
	Device new_device = remote_config_class.GetConfiguration(device);
	return install(new_device);
}

bool RunConfig::restore() {
	ifstream fs;
	fs.open("/root/.config/tuxconfig/history", ios::out);
	fs.close();
	map<string, Device> hashmap;
	map<int, Device> numbered_hashmap;
	string reply;

	if (!GetOS::is_gui_present()) {

		int count = 1;

		for (std::map<string, Device>::iterator it = hashmap.begin();
				it != hashmap.end(); ++it) {
			numbered_hashmap.insert(pair<int, Device>(count, it->second));
		}
		cout << "Which device install went wrong?";
		for (std::map<int, Device>::iterator it = numbered_hashmap.begin();
				it != numbered_hashmap.end(); ++it) {
			cout << it->first << " " << it->second.getDescription();
		}
		cin >> reply;
	}
	int int_reply = stoi(reply);

	string rollback_command =
			" x-terminal-emulator -e tar -xvf /var/lib/tuxconfig/lib_backup-"
					+ numbered_hashmap.find(int_reply)->second.getDeviceid()
					+ "-"
					+ numbered_hashmap.find(int_reply)->second.getStatus();
	int result = system(rollback_command.c_str());

	if (result == 0) {
		return true;
	}
	return false;
}

void RunConfig::setAnswer(string answer) {
	test_result = answer;
}

