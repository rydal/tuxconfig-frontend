/*
 * Feedback.cpp
 *
 *  Created on: 9 Sep 2018
 *      Author: roberty
 */

#include "Feedback.h"
string result_string;
Feedback::Feedback(Device& device, bool successful) {
    // TODO Auto-generated constructor stub
	ostringstream os;
		string url = "https://linuxconf.feedthepenguin.org/hehe/reportback?";
		if (successful == true) {
		url +=  "success=true";
        string works_history = "echo " + device.getDeviceid() + "," + device.getDescription() + "," + to_string(device.getVoteDifference())   + "," + device.getCommit() + ","  + device.getSuccessCode() + "," + device.getDescription() + ", works >> /var/lib/tuxconfig/history";
        system(works_history.c_str());
		}
		else {
			url +=  "success=false";

            string fails_history = "echo " + device.getDeviceid() + "," + device.getDescription() + "," + to_string(device.getVoteDifference())+ "," + device.getCommit()  + "," + device.getSuccessCode() + "," + device.getDescription() + ", failed >> /var/lib/tuxconfig/history";
            system(fails_history.c_str());

		}
        url += "code=" + device.getSuccessCode();
        url += "&git_url=" + device.getGitUrl();
        url += "&device_id=" + device.getDeviceid();


		os << curlpp::options::Url(url);
			 result_string =    os.str();
			 // Let's parse it

             std::istringstream myStream("/var/lib/tuxconfig/"  + device.getDeviceid() + "-install.log");
             int size = myStream.str().size();

             if (successful == false) {

              string curl_command = "/usr/bin/curl -X POST \"https://linuxconf.feedthepenguin.org/hehe/geterrorlog?code=" + device.getSuccessCode() + "&git_url=" + device.getGitUrl() + "&device_id=" + device.getDeviceid() + "\" -F 'data=@/var/lib/tuxconfig/" + device.getDeviceid() + "-install.log";
              system (curl_command.c_str());
}

}


Feedback::~Feedback() {
	// TODO Auto-generated destructor stub
}

