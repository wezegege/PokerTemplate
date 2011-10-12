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

#include <string>
using std::string;
#include <boost/program_options/options_description.hpp>
using po::options_description;
using po::value;

//- miscellanous

//-- constants

//-- types

//-- class members

//- public

//-- friend functions

//-- methods

void Container::InitDescriptors() {

}

void Container::InitParameters(int argc, char ** argv, string fileName) {
  settingManager_.ReadFromParameters(argc, argv, descriptors_);
  settingManager_.ReadFromFile(descriptors_, fileName);
}

//-- class methods

//-- operator overloads

//-- constructors - destructor

/**

*/
Container::Container() : settingManager_(), descriptors_() {

}

/**

*/
Container::~Container() {

}

//- protected

//-- methods

//- private

//-- methods


