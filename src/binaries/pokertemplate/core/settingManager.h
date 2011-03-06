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
#include "core/threadDescriptor.h"
//-- system includes

#include <boost/program_options/variables_map.hpp> 

//-- forward declarations
/// default name of the config file

namespace boost {
  namespace program_options {
    class options_description;
  }
}

namespace po = boost::program_options; 


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
    bool ReadFromParameters(int argc, char** argv, 
        const ThreadDescriptor::Vector & descriptors); 

    /**
     * read the options from the speciic configuration file, or from the indicated file. erase the saved information.
     * @param fileName name of the config file. Defaults to the constant DEFAULT_FILE_NAME
     * @param path path of the config file. Defaults to the constant DEFAULT_FILE_PATH
     * @return whether the operation went well or not
     */
    bool ReadFromFile(const ThreadDescriptor::Vector & descriptors, 
        const std::string & fileName);

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
      T GetSetting(std::string settingName) const;

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

    void ListOptions(const ThreadDescriptor::Vector & descs, po::options_description & options);

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

    po::variables_map variablesMap_;
}; // class SettingManager

//- nonmember functions

//- inline and template definitions file include
//#include "core/settingManager-inl.h"

#endif // POKERTEMPLATE_CORE_SETTINGMANAGER_H_

