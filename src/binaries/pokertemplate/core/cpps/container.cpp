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
* implementation of class Container
*/

//- includes
//-- personnal includes

#include "core/container.h"

//-- system includes

#include <boost/program_options/options_description.hpp>
using po::options_description;

//- miscellanous

//-- constants

//-- types

//-- class members

//- public

//-- friend functions

//-- methods
void Container::InitParameters(int argc, char ** argv) {
  options_description generic("Generic options");
  generic.add_options()
    ("version,v", "print version string")
    ("help-module", value<string>(),
             "produce a help for a given module")
    ("help,h", "produce help message")
    ;

  options_description config("Configuration");
  config.add_options()

    ;

  options_descriptions hidden("Hidden options");
  hidden.add_options()

    ;


  options_description cmdlineOptions;
  cmdline_options.add(generic).add(config).add(hidden);

  options_description configFileOptions;
  configFileOptions.add(config).add(hidden);

  options_description visible("Allowed options");
  visible.add(generic).add(config);

  settingManager_.ReadFromParameters(argc, argv, cmdlineOptions);
  settingManager_.ReadFromFile(configFileOptions);
}

//-- class methods

//-- operator overloads

//-- constructors - destructor

/**

*/
Container::Container() {

}

/**

*/
Container::~Container() {

}

//- protected

//-- methods

//- private

//-- methods


