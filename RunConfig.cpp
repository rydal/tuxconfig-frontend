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

vector<string> RunConfig::restore(Device& device) {
    string found_files = " find /var/lib/tuxconfig/ -name \"" + device.getDeviceid() + "*.tar\" -printf \"%T@  %p\n\" | sort -n | head -1 | sed 's/^ *//'| cut -d\" \" -f2- ";
    string restorefile = GetOS::exec(found_files.c_str());
        string runfile = "";
        runfile += "#! /bin/bash \n";
        runfile += "set -e \n";

        runfile += "exec > >(tee -i /var/lib/tuxconfig/" + device.getDeviceid() + ".log) \n";
        runfile += "function cleanup() { \n";
        runfile += "kill -SIGUSR2 " + to_string(::getpid()) + " \n";
        runfile += "} \n";
        runfile += "tar -C / -xvf " +  restorefile + "\n";
        if (device.getAptInstalled()) {
        string apt_undo_file= "/root/.aptundo/lastundo";
            runfile +="bash " + apt_undo_file + "\n";
        }

        string restore_run_file = "/usr/src/tuxconfig-" + device.getDeviceid() + "-restore";
            std::ofstream out(restore_run_file);
            out << runfile;
            out.close();
            chmod(restore_run_file.c_str(), S_IRWXU);

            //return restore_run_file;

            vector<string> result;
            result.push_back(restore_run_file);

            return result;

}


vector<string> RunConfig::uninstall(Device& device) {

    string runfile = "#!/bin/bash\n";
    runfile += "set -e \n";
    runfile += "exec > >(tee -i /var/lib/tuxconfig/" + device.getDeviceid() + "-uninstall.log) \n";
    runfile += "function cleanup() { \n";
    runfile += "kill -SIGUSR2 " + to_string(::getpid()) + " \n";
    runfile += "} \n";
    runfile += "tar -cvpf /var/lib/tuxconfig/" + device.getDeviceid()
            + "-uninstall.tar /lib /etc/modules*  1> /dev/null\n";

    runfile += "rmmod " + device.getModulename() + " || true \n";
    runfile += "echo blacklist " + device.getModulename()
            + " >> /etc/modprobe.d/blacklist.conf \n";
    runfile += "echo uninstalled " + device.getModulename()
            + " >> /root/.config/tuxconfig/uninstalled";
    runfile += "echo Device uninstalled \n";
    string tuxconfig_config_name = "/usr/src/tuxconfig-uninstall-"
            + device.getDeviceid();
    std::ofstream out(tuxconfig_config_name, std::ios_base::out);
    out << runfile;
    out.close();
    string tuxconfig_chmod_command = "chmod u+x " + tuxconfig_config_name;
    system(tuxconfig_chmod_command.c_str());
    vector<string> result;
    result.push_back(tuxconfig_config_name);
    return (result);
}

vector<string> RunConfig::install(Device& device) {
    string runfile = "#!/bin/bash \n";
    runfile += "set -e \n";
    runfile += "exec 2> >(tee -i /var/lib/tuxconfig/" + device.getDeviceid() + "-" + device.getCommit() +  "-install.log) \n";
    runfile += "function cleanup() { \n";
    runfile +=  "echo \"" + device.getDeviceid() + "," + device.getDescription() + ","	+ to_string(device.getVoteDifference()) + "," + device.getOwnerGitId() + "," + device.getSuccessCode() + "," + device.getDevicename() +  +  "," + device.getModulename() + ", failed," + device.getCommit() + "\" >> /var/lib/tuxconfig/history  \n";

    runfile += "kill -SIGUSR2 " + to_string(::getpid()) + " \n";
    runfile += "} \n";
    runfile += "trap cleanup ERR \n";
    runfile += "touch /var/lib/tuxconfig/history \n";
    //backup /lib folder

    string filedir = device.getGitUrl();
    boost::replace_all(filedir, "https://github.com/", "");
    boost::replace_all(filedir, ".git", "");
    runfile += "echo Backing up configuration directories \n";
    runfile += "tar -cvpf /var/lib/tuxconfig/" + device.getDeviceid() +  "-" + device.getCommit()
            + "-install.tar /lib /etc/modules* 1> /dev/null  \n";

    runfile += "URL=" + device.getGitUrl() + " \n";
    runfile += "COMMIT=" + device.getCommit() + " \n";

    runfile += "rm -rf /usr/src/" + filedir + " \n";
    runfile += "mkdir -p " + filedir + "\n";
    runfile += "echo Downloading install media\n";
    runfile += "git clone $URL /usr/src/" + filedir + " 1> /dev/null \n";
    runfile += "echo git repository downloaded \n";
    runfile += "wait\n";
    runfile += "cd /usr/src/" + filedir + " \n";
    runfile += "git checkout  -b tuxconfig-branch $COMMIT\n";
    runfile += "echo commit checked out\n";
    string tuxconfig_file = "/usr/src/" + filedir + "/tuxconfig";
    runfile += "sed -i 's/^[ \t]*device_ids.*//g' " + tuxconfig_file + " \n";
    runfile += ". " + tuxconfig_file + "\n";
//install dependencies;
    runfile += " if [ !  -z \"$dependencies\" ] ; then \n";
    runfile += "apt-undo install $dependencies \n";
    runfile +=  "echo \"" + device.getDeviceid() + "," + device.getDescription() + ","	+ to_string(device.getVoteDifference()) + "," + device.getOwnerGitId() + "," + device.getSuccessCode()  + "," + device.getModulename() + ",apt-installed," + device.getCommit() + " \" >> /var/lib/tuxconfig/history  \n";

    runfile += "fi \n";
    runfile += "echo \"installed dependencies\" \n";
    runfile += "if [ -f Makefile ] ; then \n";
//Build module
    runfile += "echo Making module \n";
    runfile += "make 1> /dev/nu\n";
    runfile += "echo \"built source code\" \n";
//Install module
    runfile += "echo installing module\n";
    runfile += "make install 1> /dev/null \n";
    runfile += "echo \"installed source code\" \n";
//Insert module
    runfile += "modprobe -v $tuxconfig_module \n";
    runfile += "echo \"inserted module into kernel\" \n";
    runfile +=  "echo \"" + device.getDeviceid() + "," + device.getDescription() + ","	+ to_string(device.getVoteDifference()) + "," + device.getOwnerGitId() + "," + device.getSuccessCode() + "," + device.getModulename() +  ", module-installed,"  + device.getCommit() + " \"  >> /var/lib/tuxconfig/history  \n";
    runfile += "fi \n";
    runfile += "kill -SIGUSR1 " + to_string(::getpid()) + " \n";


    boost::replace_all(filedir, "/", "-");
    string tuxconfig_run_name = "/usr/src/tuxconfig-" + filedir;
    std::ofstream out(tuxconfig_run_name);
    out << runfile;
    out.close();

    string chmod_command = "chmod u+x " + tuxconfig_run_name;
    system(chmod_command.c_str());



    string line;
    ifstream myfile;
    myfile.open(tuxconfig_file, std::ios_base::out);
    string test_program;
    string test_message;
    string restart_needed = "false";

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (line.find("test_program=") == 0) {
                boost::replace_all(line, "test_program=", "");
                boost::replace_all(line, "\"", "");
                boost::trim(line);
                test_program = line ;

            }
            if (line.find("test_message=") == 0) {
                boost::replace_all(line, "test_message=", "");
                boost::replace_all(line, "\"", "");
                boost::trim(line);
                test_message = line;

            }
            if (line.find("restart_needed=") == 0) {
                boost::replace_all(line, "restart_needed=", "");
                boost::replace_all(line, "\"", "");
                boost::trim(line);
                if( line == "yes" || line == "y") {
                    restart_needed = "true";
                }
            }

        }

    }
    //wire into boot process.
    if (restart_needed == "true") {
        string PKEXEC_UID = GetOS::exec("echo $SUDO_USER");
        boost::trim(PKEXEC_UID);
        ifstream infile;
        infile.open("/usr/share/applications/tuxconfig.desktop");
        string out_file = "/home/" + PKEXEC_UID + "/.config/autostart/tuxconfig.desktop";
        ofstream outFile(out_file.c_str(),std::ios_base::out);
        istream readFile();
        string readout;


        while(getline(infile,readout)){
          if(readout == "/usr/bin/tuxconfig"){
            outFile << "/usr/bin/tuxconfig recover";
          }
          else {
            outFile << readout;
          }
        }

        ofstream bashrc ;
         bashrc.open("/home/" + PKEXEC_UID +"/.bashrc",std::ios_base::app);
          if (bashrc.is_open())
          {
            bashrc << "/usr/bin/tuxconfig recover";

          }

          bashrc.close();
    }

     vector<string> result;
     result.push_back(tuxconfig_run_name);
     result.push_back(test_program);
     result.push_back(test_message);
     result.push_back(restart_needed);


     return result;
}



vector<string> RunConfig::upgrade(Device& device) {
    GetRemoteConfig remote_config_class;
    Device new_device = remote_config_class.GetConfiguration(device);
    return install(new_device);

}

bool RunConfig::restoreCmd(Device& device) {
    ifstream fs;
    fs.open("/var/lib/tuxconfig/history", ios::out);
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
            "tar -xvf /var/lib/tuxconfig/"
                    + numbered_hashmap.find(int_reply)->second.getDeviceid()
                    + "-"
                    + numbered_hashmap.find(int_reply)->second.getCommit()
                    + numbered_hashmap.find(int_reply)->second.getStatus();
    int result = system(rollback_command.c_str());
    if (result == 0) {
        return true;
    } else {
        return false;
    }

}
