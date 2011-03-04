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
* implementation of class SettingManager
*/

//- includes
//-- personnal includes

#include "core/settingManager.h"

//-- system includes

using po::options_description;
using po::positional_options_description;
using po::store;
using po::command_line_parser;
using po::parse_config_file;

//- miscellanous

//-- constants

//-- types

//-- class members

//- public

//-- friend functions

//-- methods

bool SettingManager::ReadFromParameters(int argc, char ** argv, 
    const options_description & toCheck, 
    const positional_options_description & positions) {
  store(command_line_parser(argc, argv).options(toCheck).positional(positions).run(), variablesMap_);
}

bool SettingManager::ReadFromFile(options_description toCheck,
    const std::string & fileName) {
  store(parse_config_file(fileName, toCheck), variablesMap_);
}

//-- class methods

//-- operator overloads

//-- constructors - destructor

/**

*/
SettingManager::SettingManager() {

}

/**

*/
SettingManager::~SettingManager() {

}

//- protected

//-- methods

//- private

//-- methods


