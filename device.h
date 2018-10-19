    /*
 * deviceinfo.h
 *
 *  Created on: 25 Aug 2018
 *      Author: roberty
 */

#ifndef DEVICE_H_
#define DEVICE_H_

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/detail/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <fstream>
#include <string>
#include <vector>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <jsoncpp/json/json.h>
#include <sstream>
#include <boost/algorithm/string/trim_all.hpp>
#include "GetOS.h"


class Device {
	public:
	Device();
	Device(string id, string description, string name, string modulename);

	Device(string m_id,  string m_description, bool isInstalled, bool isFailed);
	string parseDeviceId(string device_id);


	bool operator< (const Device rhs) const ;
	bool operator< (const Device rhs);
	bool isUpgradeable();
	string getInstalledStatus();
	Device getinfo();
	const std::string& getCommit() const;

	void setCommit(const std::string& commit);

	const std::string& getDescription() const;

	void setDescription(const std::string& description);

	const std::string& getDeviceid() const;

	void setDeviceid(const std::string& deviceid);

	const std::string& getGitUrl() const ;

	void setGitUrl(const std::string& gitUrl);

	const std::string& getModulename() const ;

	void setModulename(const std::string& modulename) ;
	const std::string& getOwnerGitId() const ;

	void setOwnerGitId(const std::string& ownerGitId) ;

	const std::string& getSuccessCode() const;

	void setSuccessCode(const std::string& successCode);

	const std::string& getDevicename() const;

	void setDevicename(const std::string& devicename);

	const std::string& getSetCommand() const;

	void setSetCommand(const std::string& setCommand);

	const int& getVoteDifference() const ;

	void setVoteDifference(const int& voteDifference) ;

	const bool getAttemptedInstall() const ;

	void setAttemptedInstall(bool installed);

	std::string deviceid;
	std::string modulename;
	std::string	description;
	std::string commit;
	std::string git_url;
	std::string success_code;
	std::string owner_git_id;
	std::string devicename;
	std::string setCommand;
    std::string AptInstalled;

	bool attempted_install;
	int vote_difference;
	bool is_upgradeable;
	bool is_installed;

    string status;
    const string& getStatus() const;
    void setStatus(const string& status);

	bool isIsUpgradeable() const {
		return is_upgradeable;
	}

	void setIsUpgradeable(bool isUpgradeable) {
		is_upgradeable = isUpgradeable;
	}

	bool isIsInstalled() const {
		return is_installed;
	}

	void setIsInstalled(bool isInstalled) {
		is_installed = isInstalled;
    }
    void setAptInstalled(const std::string& apt_install);

    const std::string& getAptInstalled() const;
};










#endif /* DEVICE_H_ */
