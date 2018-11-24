#include "GetRemoteConfig.h"

using namespace std;


GetRemoteConfig::GetRemoteConfig() {

}

GetRemoteConfig::~GetRemoteConfig() {

}

Device GetRemoteConfig::GetConfiguration(Device& configured_device) {
    int attempt_number = 1;
    //check number  of attempts
    ifstream inFile("/var/lib/tuxconfig/history");
    string x;
    if (inFile.is_open()) {
       while (getline(inFile, x)) {

            if (x.find(configured_device.getDeviceid()) != std::string::npos && x.find("failed") != std::string::npos)  {
                attempt_number++;
            }
		}
		inFile.close();
	}

	string* os_string = GetOS::getLocalMchineDistro();
	ostringstream os;

    cout<<"Attempt number:"<<attempt_number<<endl;
    string url = "https://linuxconf.feedthepenguin.org/hehe/getdevice?deviceid="+ configured_device.getDeviceid() + "&attempt="	+ to_string(attempt_number) + "&distribution=" + os_string[0];

	os << curlpp::options::Url(url);
	string str = os.str();
	Json::Value root;
	Json::Reader reader;

	bool parsingSuccessful = reader.parse(str, root);
	if (!parsingSuccessful) {

		exit(1);
	}
	if (!root.isMember("Error")) {
		string url = root["git_url"].asString();
		string success_code = root["success_code"].asString();
		string vote_difference = root["vote_difference"].asString();
		string owner_git_id = root["owner_git_id"].asString();
		string commit_hash = root["commit_hash"].asString();
        string module = root["module"].asString();

		configured_device.setGitUrl(url);
		configured_device.setSuccessCode(success_code);
		configured_device.setVoteDifference(stoi(vote_difference));
		configured_device.setCommit(commit_hash);
		configured_device.setOwnerGitId(owner_git_id);
        configured_device.setModulename(module);
	} else {
		configured_device.setGitUrl("null");

	}
	string line;
     ifstream inputFile("/var/lib/tuxconfig/history");
	  string tempLine;
	  while ( getline(inputFile, tempLine, '\n') ) {
	    vector <string> tempstr;
	    stringstream ss(tempLine);
	    string temp;
	    while (getline(ss, temp, ',')) {
            boost::trim(temp);
	      tempstr.push_back(temp);
	    }
        if (tempstr[0] == configured_device.getDeviceid() && tempstr[6].find("works") != string::npos) {
	    	if (stoi(tempstr[2]) < configured_device.getVoteDifference()) {
	    		configured_device.setIsUpgradeable(true);
            }


            configured_device.setSuccessCode(tempstr[4]);

            configured_device.setIsInstalled(true);
            configured_device.setStatus("works");
	    }

        if (tempstr[0] == configured_device.getDeviceid() && tempstr[6].find("failed") != string::npos) {
            configured_device.setIsInstalled(true);
            configured_device.setSuccessCode(tempstr[4]);
            configured_device.setStatus("failed");

	    }
	  }


	curlpp::Cleanup mycleanup;

	return configured_device;
}
