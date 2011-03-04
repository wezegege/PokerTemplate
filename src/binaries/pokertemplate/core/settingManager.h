/**
 * @author Kevin TRAN
 * @date 04/03/2011
 * @section LICENSE
 *
 * This file is part of Pokertemplate.
 *
 * Pokertemplate is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Pokertemplate is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Pokertemplate.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Header for class SettingManager
 */

#ifndef POKERTEMPLATE_CORE_SETTINGMANAGER_H_
#define POKERTEMPLATE_CORE_SETTINGMANAGER_H_

//- includes
//-- personnal includes

//-- system includes
#include <boost/any.hpp>
#include <string>
#include <map>
//-- forward declarations
static const std::string DEFAULT_CONFIG_FILE = "config.ini"; ///< default name of the config file
static const std::string DEFAULT_CONFIG_PATH = "."; ///< default path of the configuration file

class Setting {
  public:
    template<typename T>
      void SetValue(T value);
    template<typename T>
      T GetValue();
template<typename T>
Setting(std::string label, std::string description, std::string shortcut, T value);
  private:
    boost::any value_;
    const std::string label_;
    const std::string description_;
    const std::string shortcut_;
};

/**

*/
class SettingManager {
  //- public
  public:
    //-- typedefs and enums

    //-- constants

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
    bool ReadFromFile(const std::string & fileName = DEFAULT_CONFIG_FILE, const std::string & path = DEFAULT_CONFIG_PATH);

    /**
     *
     * @return 
     */        
    bool CreateDefaultSettings();

    /**
     * manually set a setting
     * @param settingName the parameter name
     * @param value the parameter value
     */
    template<typename T>
      void SetSetting(std::string settingName, T value);

    /**
     * get a setting's value
     * @param settingName the parameter name
     * @return the setting value
     */
    template<typename T>
      T GetSetting(std::string settingName);

    //-- operator overloads

    //-- constructors - destructor
    /**
     * default constructor
     */
    SettingManager();

    /*

     * Destructor
     */
    virtual ~SettingManager();


    //- protected
  protected:
    //-- typedefs and enums

    //-- constants

    //-- methods

    //-- data members

    //- private
  private:
    //-- typedefs and enums

    //-- constants

    //-- methods

    /**
     * assignment operator overload
     * @param aSettingManager the value of the assignment
     * @return a reference to itself
     */
    SettingManager & operator=(const SettingManager & aSettingManager);

    /**
     * copy constructor
     * @param aSettingManager the value of the assignment
     */
    explicit SettingManager(const SettingManager & aSettingManager);

    //-- data members
    std::map<std::string, Setting> data_; ///< dictionnaryfor the parameters

}; // class SettingManager

//- nonmember functions

//- inline and template definitions file include
#include "core/settingManager-inl.h"

#endif // POKERTEMPLATE_CORE_SETTINGMANAGER_H_

