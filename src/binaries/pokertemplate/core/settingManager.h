/**
 * @author Kevin TRAN
 * @date 27/11/2010
 * @section LICENSE
 *
 * This file is part of £PROJECT£.
 * 
 * £PROJECT£ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * £PROJECT£ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with £PROJECT£.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Header for class SettingManager
 */
 
#ifndef £PROJECT£_SETTINGMANAGER_H_
#define £PROJECT£_SETTINGMANAGER_H_

//- includes
//-- personnal includes

//-- system includes
#include <string>
#include <map>

//-- forward declarations

/**
 * Manage options from parameters or from the config file.
 * 
 * Read options passed to application, or read from file, then informs the differents modules about their values. Manage general preferences about the application such as resolution, admin properties, ... . Each game has its own settings manager.
 */
public class SettingManager {
//- public
public:
//-- typedefs and enums

//-- constants
	static const std::string DEFAULT_FILE_NAME = "config.ini"; ///< default name of the configuration file
	static const std::string DEFAULT_FILE_PATH = "."; ///< default path of the configuration file

//-- methods
	/**
	 * Read the options passed to the main function, and interpret them to fill the preferences. Has priorities on file based preferences
	 * @param argc the argument count, passed to main function
	 * @param argv the argument values, passed to main function
	 * @return whether the operation went well or not
	 */
	bool ReadFromParameters(int argc, char** argv);
	
	/**
	 * read the options from the speciic configuration file, or from the indicated file. erase the saved information.
	 * @param fileName name of the config file. Defaults to the constant DEFAULT_FILE_NAME
	 * @param path path of the config file. Defaults to the constant DEFAULT_FILE_PATH
	 * @return whether the operation went well or not
	 */
	bool ReadFromFile(std::string fileName = DEFAULT_FILE_NAME, std::string path = DEFAULT_FILE_PATH);
	
	bool CreateDefaultSettings();
	
	/**
	 * manually set a setting
	 * @param settingName the parameter name
	 * @param value the parameter value
	 */
	template<typename T>
		void SetSetting<T>(std::string settingName, T value);
	
	/**
	 * get a setting's value
	 * @param settingName the parameter name
	 * @return the setting value
	 */
	template<typename T>
	std::string GetStringSetting<T>(std::string settingName);

//-- operator overloads
	
//-- constructors - destructor
	/**
	 * default constructor
	 */
	SettingManager();

	/**
	 * Destructor
	 */
	~SettingManager();

//- private
private:

//-- methods

	/**
	 * assignment operator overload
	 * should not be used (noncopyable object)
	 * @param aSettingManager the value of the assignment
	 * @return a reference to itself
	 */
	SettingManager & operator=(const SettingManager & aSettingManager);
	
	/**
	 * copy constructor
	 * should not be used (noncopyable object)
	 * @param aSettingManager the value of the assignment
	 */
	explicit SettingManager(const SettingManager & aSettingManager);

//-- private data members
	std::map<std::string, std::string> stringData_; ///< map for the string parameters
	std::map<std::string, int> intData_; ///< map for the integer parameters
	std::map<std::string, bool> boolData_; ///< map for the boolean parameters
} // class SettingManager

//- nonmember functions

//- inline and template definitions file include
//#include "SettingManager_inl.h"

#endif // £PROJECT£_CORE_SETTINGMANAGER_H_
