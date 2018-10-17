/*
 * Feedback.cpp
 *
 *  Created on: 9 Sep 2018
 *      Author: roberty
 */

#include "Feedback.h"
string result_string;
Feedback::Feedback(Device device, bool successful) {
	// TODO Auto-generated constructor stub
	ostringstream os;
		string url = "https://linuxconf.feedthepenguin.org/hehe/reportback?";
		if (successful == true) {
		url +=  "success=true";
		}
		else {
			url +=  "success=false";

		}
		url += "code" + device.getSuccessCode();
		url += "git_url" + device.getGitUrl();
		url += "device_id" + device.getGitUrl();
		os << curlpp::options::Url(url);
			 result_string =    os.str();
			 // Let's parse it

             std::istringstream myStream("/var/lib/tuxconfig/"  + device.getDeviceid()+ "-install.log");
             int size = myStream.str().size();

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
                 request.setOpt(new Upload(true));
                 request.setOpt(new HttpHeader(headers));
                 request.setOpt(new Url(url));

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


Feedback::~Feedback() {
	// TODO Auto-generated destructor stub
}

