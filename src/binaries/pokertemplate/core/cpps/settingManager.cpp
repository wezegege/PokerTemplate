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

using po::store;
#include <boost/program_options/options_description.hpp>
using po::options_description;
#include <boost/program_options/parsers.hpp>
using po::value;
using po::command_line_parser;
using po::parse_config_file;
#include <boost/filesystem/fstream.hpp>
using boost::filesystem::fstream;
using boost::filesystem::path;
#include <string>
using std::string;

//- miscellanous

//-- constants

//-- types

//-- class members

//- public

//-- friend functions

//-- methods

bool SettingManager::ReadFromParameters(int argc, char ** argv, 
    const ThreadDescriptor::Vector & descriptors) {
  options_description generic("Generic options");
  generic.add_options()
    ("version,v", "print version string")
    ("help-module", value<string>(),
     "produce a help for a given module")
    ("help,h", "produce help message")
    ;

  options_description options;
  options.add(generic);
  ListOptions(descriptors, options);

  store(command_line_parser(argc, argv).options(options).run(), variablesMap_);
}

bool SettingManager::ReadFromFile(const ThreadDescriptor::Vector & descriptors,
    const std::string & fileName) {

  options_description options;
  ListOptions(descriptors, options);

  path file(fileName);
  fstream fileHandle;
  fileHandle.open(file, std::ios_base::out);
  store(parse_config_file(fileHandle, options), variablesMap_);
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

void SettingManager::ListOptions(const ThreadDescriptor::Vector & descs, options_description & options) {
  ThreadDescriptor::Vector::const_iterator it = descs.begin();
  for(;it != descs.end(); ++it) {
    options.add(it->GetOptions());
  }
}
