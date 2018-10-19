/*
 * deviceinfo.cpp
 *
 *  Created on: 21 Aug 2018
 *      Author: roberty
 */
#include "device.h"
using namespace std;


	struct MyException : public std::exception
{
   std::string s;
   MyException(std::string ss) : s(ss) {}
   ~MyException() throw () {} // Updated
   const char* what() const throw() { return s.c_str(); }
};
	bool Device::isUpgradeable() {

	return is_upgradeable;
	}


Device::Device() {

		}
	Device::Device(string m_id,  string m_description, string m_name, string m_modulename )
	: deviceid(m_id),description(m_description),devicename(m_name),modulename(m_modulename),vote_difference(0),git_url("null"),is_upgradeable(false),attempted_install(false){
	     		}
	Device::Device(string m_id,  string m_description, bool isInstalled, bool isFailed)
	: deviceid(m_id),description(m_description), is_installed(isInstalled), attempted_install(isFailed){


		     	this->description = m_description;
		     	this->deviceid = m_id;
		}



	bool Device::operator< (Device lhs)    { if  (description.compare(lhs.description) <= 0 ) {return true; } else {return false; } }  ;

	bool Device::operator< (const Device lhs) const   { if (description.compare(lhs.description) <= 0 ) {return true; } else {return false; } }  ;


	Device Device::getinfo() {
		return *this;
	}

	const std::string& Device::getCommit() const {
		return commit;
	}

	void Device::setCommit(const std::string& commit) {
		this->commit = commit;
	}

	const std::string& Device::getDescription() const {
		return description;
	}

	void Device::setDescription(const std::string& description) {
		this->description = description;
	}

	const std::string& Device::getDeviceid() const {
		return deviceid;
	}

	void Device::setDeviceid(const std::string& deviceid) {
		if (deviceid.length() != 9) {
			std::vector<std::string> results;
			vector<string> strs;
			boost::split(strs,deviceid,boost::is_any_of(":"));
			if (strs.size() == 2) {
			this->deviceid = strs[1] + ":" + strs[2];
			}
		} else {
		this->deviceid = deviceid;
		}
	}

	const std::string& Device::getGitUrl() const {
		return git_url;
	}

	void Device::setGitUrl(const std::string& gitUrl) {
		git_url = gitUrl;
	}

	const std::string& Device::getModulename() const {
		return modulename;
	}

	void Device::setModulename(const std::string& modulename) {
		this->modulename = modulename;

	}

	const std::string& Device::getOwnerGitId() const {
		return owner_git_id;
	}

	void Device::setOwnerGitId(const std::string& ownerGitId) {
		owner_git_id = ownerGitId;

	}

	const std::string& Device::getSuccessCode() const {
		return success_code;
	}

	void Device::setSuccessCode(const std::string& successCode) {
		success_code = successCode;
	}
	const std::string& Device::getDevicename() const {
		return devicename;
	}

	void Device::setDevicename(const std::string& devicename) {
		this->devicename = devicename;
	}

    const std::string& Device::getSetCommand() const {
        return setCommand;
    }

    void Device::setSetCommand(const std::string& setCommand) {
        this->setCommand = setCommand;
    }

	const int& Device::getVoteDifference() const {
		return vote_difference;
	}

	void Device::setVoteDifference(const int& voteDifference) {
		vote_difference = voteDifference;
	}

	const bool Device::getAttemptedInstall() const {
		return attempted_install;
	}

	void Device::setAttemptedInstall(bool installed) {
		this->attempted_install = installed;
	}

    const string& Device::getStatus() const {
            return status;
        }

        void Device::setStatus(const string& status) {
            this->status = status;
        }




