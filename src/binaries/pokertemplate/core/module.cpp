/**
* @author Kevin TRAN
* @date 01/03/2011
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
* implementation of class Module
*/

//- includes
//-- personnal includes

#include "core/module.h"

//-- system includes

using std::vector;

//- miscellanous

//-- constants

//-- types

//-- class members

//- public

//-- friend functions

//-- methods

void Module::Create(Thread::Ptr thread) throw(WrongThreadException, UniqueThreadException) {
 if(thread == 0) {
  throw WrongThreadException();
 }
 thread->Start();
 threads_.push_back(thread);
}

void Module::Join(int index) throw(NoThreadException) {
  threads_.at(index)->Join();
}


void Module::Destroy() throw(NoThreadException) {
  vector<Thread::Ptr>::iterator it = threads_.begin();
  for(; it < threads_.end(); ++it) {
    (*it)->Cancel();
  }
}

//-- class methods

//-- operator overloads

//-- constructors - destructor

/**

*/
Module::Module() {

}

/**

*/
Module::~Module() {

}

//- protected

//-- methods

//- private

//-- methods


