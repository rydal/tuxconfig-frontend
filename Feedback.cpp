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
        string url = "https://linuxconf.feedthepenguin.org/live/reportback?";
		if (successful == true) {
		url +=  "success=true";
         string works_history =  "echo \"" + device.getDeviceid() + "," + device.getDevicename() + ","	+ to_string(device.getVoteDifference()) + "," + device.getOwnerGitId() + "," + device.getSuccessCode() + "," + device.getModulename() +  ",works," + device.getCommit() + "\" >> /var/lib/tuxconfig/history  \n";

        system(works_history.c_str());
		}
		else {
			url +=  "success=false";

            string fails_history =  "echo \"" + device.getDeviceid() + "," + device.getDevicename() + ","	+ to_string(device.getVoteDifference()) + "," + device.getOwnerGitId() + "," + device.getSuccessCode() + ","  + device.getModulename() +  ",failed," + device.getCommit() + "\" >> /var/lib/tuxconfig/history  \n";
            system(fails_history.c_str());

		}
        url += "&code=" + device.getSuccessCode();
        url += "&git_url=" + device.getGitUrl();
        url += "&device_id=" + device.getDeviceid();
        url += "&commit_hash=" + device.getCommit();

        string curl_command = "/usr/bin/curl -X POST \"" + url + "\"";
        system (curl_command.c_str());


        if (successful == false) {
            curlpp::Easy easyhandle;
                   easyhandle.setOpt(curlpp::options::Url(url));
                    easyhandle.setOpt(new curlpp::options::WriteStream(&os));
                   easyhandle.perform();

			 result_string =    os.str();
			 // Let's parse it

             std::istringstream myStream("/var/lib/tuxconfig/"  + device.getDeviceid() + "-" + device.getCommit() + "-install.log");
             int size = myStream.str().size();

              string curl_command = "/usr/bin/curl -X POST \"https://linuxconf.feedthepenguin.org/live/geterrorlog?code=" + device.getSuccessCode() + "&git_url=" + device.getGitUrl() + "&device_id=" + device.getDeviceid() + "\" -F 'data=@/var/lib/tuxconfig/" + device.getDeviceid() + "-install.log'";
              cout<<"curl command = "<<curl_command<<endl;

              system (curl_command.c_str());
             }
}




Feedback::~Feedback() {
	// TODO Auto-generated destructor stub
}

