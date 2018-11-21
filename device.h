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
    /** Default constructor.
     * @brief Device
     */
	Device();
    /** Constructor as used in downloading remote configuration.
     * @brief Device
     * @param id
     * @param description
     * @param name
     * @param modulename
     */
    Device(string id, string description, string name, string modulename);
    /** Constructor as used when obtaining information from history file.
     * @brief Device
     * @param m_id
     * @param m_description
     * @param isInstalled
     * @param isFailed
     * @param success_code
     * @param status
     */
    Device(string m_id,  string m_description, bool isInstalled, bool isFailed, string success_code,string status);
    /** Parses device id to match that of databse
     */
    string parseDeviceId(string device_id);

    /** Sorts items when referred by hashmap (const).
     * @brief operator <
     * @param rhs
     * @return true if this < lhs.
     */
	bool operator< (const Device rhs) const ;
    /** Sorts items when referred by hashmap
     * @brief operator <
     * @param rhs
     * @return true if this < lhs (const)
     */
    bool operator< (const Device rhs);
    /** Returns true if vote count less than in database.
     * @brief isUpgradeable
     * @return true if remote server vote count higher than this vote count.
     */
	bool isUpgradeable();
    /** returns install status as found in history file.
     * @brief getInstalledStatus
     * @return failed, works or installed.
     */
	string getInstalledStatus();
    /** Returns device object.
     * @brief getinfo
     * @return device.
     */
	Device getinfo();
    /** Returns commit hash.
     * @brief getCommit
     * @return commit hash when downloaded install attempted.
     */
	const std::string& getCommit() const;
    /** sets commit hash.
     * @brief setCommit
     * @param commit
     */
	void setCommit(const std::string& commit);
    /** returns device description as found locally..
     * @brief getDescription
     * @return description as defined in lshw
     */
	const std::string& getDescription() const;
    /** Sets device description as found locally.
     * @brief setDescription
     * @param description
     */
	void setDescription(const std::string& description);

    /** returns device id.
     * @brief getDeviceid
     * @return device id as in lshw -numeric.
     */
	const std::string& getDeviceid() const;
    /** sets device id.
     * @brief setDeviceid
     * @param deviceid
     */
	void setDeviceid(const std::string& deviceid);
    /** returns device's remote repository url.
     * @brief getGitUrl
     * @return as found in database.
     */
	const std::string& getGitUrl() const ;
    /** sets device's repository url.
     * @brief setGitUrl
     * @param gitUrl
     */
	void setGitUrl(const std::string& gitUrl);
    /** returns module name as defined in tuxconfig file in repository.
     * @brief getModulename
     * @return modulename as defined in tuxconfig.
     */
	const std::string& getModulename() const ;

    /** sets  module name as defined in tuxconfig file in repository.
     * @brief setModulename
     * @param modulename
     */
    void setModulename(const std::string& modulename) ;
    /** returns contibutors github.com user id.
     * @brief getOwnerGitId
     * @return returns owner_git_id as found when device downloaded.
     */
	const std::string& getOwnerGitId() const ;
    /** sets contributors github.com user id.
     * @brief setOwnerGitId
     * @param ownerGitId
     */
	void setOwnerGitId(const std::string& ownerGitId) ;

    /**
     * @brief getSuccessCode
     * @return  success code of a particular installation as defined in backend database.
     */
	const std::string& getSuccessCode() const;

    /** sets  success code of a particular installation as defined in backend database.
     * @brief setSuccessCode
     * @param successCode
     */
	void setSuccessCode(const std::string& successCode);

    /** reutrns device name
     * @brief getDevicename
     * @return as found using lshw.
     */
	const std::string& getDevicename() const;
    /** sets device name as found on local system.
     * @brief setDevicename
     * @param devicename
     */
	void setDevicename(const std::string& devicename);

    /** Not used.
     * @brief getSetCommand
     * @return
     */
	const std::string& getSetCommand() const;

    /** Not used.
     * @brief setSetCommand
     * @param setCommand
     */
	void setSetCommand(const std::string& setCommand);
    /** Returns the success of the device's install as downloaded.
     * @brief getVoteDifference
     * @return
     */
	const int& getVoteDifference() const ;
    /** sets the success of the device's install as downloaded.
     * @brief setVoteDifference
     * @param voteDifference
     */
	void setVoteDifference(const int& voteDifference) ;
    /** returns true if an attempred install of the device has been made.
     * @brief getAttemptedInstall
     * @return
     */
	const bool getAttemptedInstall() const ;
    /** sets true if an attempred install of the device has been made
     * @brief setAttemptedInstall
     * @param installed
     */
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
    bool AptInstalled;

	bool attempted_install;
	int vote_difference;
	bool is_upgradeable;
	bool is_installed;

    string status;
    /** Returns device install status as found in history.
     * @brief getStatus
     * @return
     */
    const string& getStatus() const;
    /** sets device install status as found in history.
     * @brief setStatus
     * @param status
     */
    void setStatus(const string& status);

    /** returns true if vote count of device is less than that of remote verison.
     * @brief isIsUpgradeable
     * @return
     */
	bool isIsUpgradeable() const {
		return is_upgradeable;
	}
    /** sets true if vote count of device is less than that of remote verison.
     * @brief setIsUpgradeable
     * @param isUpgradeable
     */
	void setIsUpgradeable(bool isUpgradeable) {
		is_upgradeable = isUpgradeable;
	}
    /** Returns true if device is installed.
     * @brief isIsInstalled
     * @return
     */
	bool isIsInstalled() const {
		return is_installed;
	}
    /** sets true if device is installed.
     * @brief setIsInstalled
     * @param isInstalled
     */
	void setIsInstalled(bool isInstalled) {
		is_installed = isInstalled;
    }
    /** sets to true if packages were installed using apt-undo.
     * @brief setAptInstalled
     * @param apt_install
     */
    void setAptInstalled( bool  apt_install);
    /** Returns true if packages were installed using apt-undo.
     * @brief getAptInstalled
     * @return
     */
    bool getAptInstalled() ;
};










#endif /* DEVICE_H_ */
