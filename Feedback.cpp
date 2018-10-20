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
        string works_history = "echo " + device.getDeviceid() + "," + device.getDescription() + "," + to_string(device.getVoteDifference())
                + "," + device.getCommit()  + ", works >> /var/lib/tuxconfig/history";
        system(works_history.c_str());
		}
		else {
			url +=  "success=false";

            string fails_history = "echo " + device.getDeviceid() + "," + device.getDescription() + "," + to_string(device.getVoteDifference())
                    + "," + device.getCommit()  + ", failed >> /var/lib/tuxconfig/history";
            system(fails_history.c_str());

		}
        url += "&code=" + device.getSuccessCode();
        url += "&git_url=" + device.getGitUrl();
        url += "&device_id=" + device.getDeviceid();


		os << curlpp::options::Url(url);
			 result_string =    os.str();
			 // Let's parse it

             std::istringstream myStream("/var/lib/tuxconfig/"  + device.getDeviceid() + "-install.log");
             int size = myStream.str().size();

             if (successful == false) {

             char buf[50];
              try
              {
                 curlpp::Cleanup cleaner;
                 curlpp::Easy request;

                 std::list< std::string > headers;
                 headers.push_back("Content-Type: text/*");
                 sprintf(buf, "Content-Length: %d", size);
                 headers.push_back(buf);

                 using namespace curlpp::Options;
                 request.setOpt(new Verbose(true));
                 request.setOpt(new ReadStream(&myStream));
                 request.setOpt(new InfileSize(size));
                 request.setOpt(new HttpHeader(headers));

                 string error_log_url =  "https://linuxconf.feedthepenguin.org/hehe/geterrorlog?";
                 error_log_url += "&code=" + device.getSuccessCode();
                 error_log_url += "&git_url=" + device.getGitUrl();
                 error_log_url += "&device_id=" + device.getDeviceid();

                 request.setOpt(new Url(error_log_url));

                 request.perform();
              }
              catch ( curlpp::LogicError & e )
                {
                  std::cout << e.what() << std::endl;
                }
              catch ( curlpp::RuntimeError & e )
                {
                  std::cout << e.what() << std::endl;
                }

}

}


Feedback::~Feedback() {
	// TODO Auto-generated destructor stub
}

