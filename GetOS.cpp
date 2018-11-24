/*
 * GetOS.cpp
 *
 *  Created on: 2 Sep 2018
 *      Author: roberty
 */

#include "GetOS.h"

std::string GetOS::exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}

GetOS::GetOS() {

    // TODO Auto-generated constructor stub

}

GetOS::~GetOS() {
    // TODO Auto-generated destructor stub
}

std::string* GetOS::getLocalMchineDistro() {
     string line;
     string* array = new string[4];
     string name;
     string linux_version;
     string architecture;
     string kernel_version;

     std::string output = exec("cat /etc/*-release");
        std::stringstream iss(output);

      if (iss.good())
      {
        while ( getline (iss,line) )
        {
         if(line.find("NAME") == 0) {
            boost::replace_all(line, "NAME=\"", "");
            boost::replace_all(line, "\"", "");
            boost::replace_all(line, "GNU/Linux","");
            boost::to_lower(line);
            name = line;


         }
         if(line.find("VERSION_ID") == 0 ) {
                    boost::replace_all(line, "VERSION_ID=\"", "");
                    boost::replace_all(line, "\"", "");
                    linux_version = line;
                 }
        } }	   else {


      }
       architecture = GetOS::exec("uname -m");
       kernel_version = GetOS::exec("uname -r");
        std::regex re("-[0-9].*");
        std::regex re2("\\.0\\s*$");

        kernel_version = std::regex_replace(kernel_version,re,"");
        kernel_version = std::regex_replace(kernel_version,re2,"");



      boost::algorithm::to_lower(name); // modifies str
      boost::algorithm::to_lower(linux_version); // modifies str
      boost::algorithm::to_lower(architecture); // modifies str
      boost::algorithm::to_lower(kernel_version); // modifies str
      boost::trim(name);
      boost::trim(linux_version); // modifies str
      boost::trim(architecture); // modifies str
      boost::trim(kernel_version); // modifies str

     // array[0] = name;
      array[0] = name;
      array[1] = linux_version;
      array[2] = architecture;
      array[3] = kernel_version;
      return array;
}

bool GetOS::is_gui_present() {

if (NULL == getenv("DISPLAY")) return false;
else return true;
}

void GetOS::runWebpage(string url)  {

    string runCommand = "sudo -u $SUDO_USER x-www-browser " + url;
    system(runCommand.c_str());
}
void GetOS::runEmail(string email)  {
    string runCommand = "sudo -u $SUDO_USER xdg-open mailto://" + email;
    system(runCommand.c_str());
}



void GetOS::reset_reboot() {
        string PKEXEC_UID = GetOS::exec("echo $SUDO_USER");
                boost::trim(PKEXEC_UID);

        string remove_bash_rc_line = "sed 's,sudo /usr/bin/tuxconfig_cmd recover,,g' /home/" + PKEXEC_UID + "/.bashrc";
        system(remove_bash_rc_line.c_str());
        string desktop_file = PKEXEC_UID + "/.config/autostart/tuxconfig.desktop";
        remove(desktop_file.c_str());




}


