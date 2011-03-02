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
* implementation of class Thread
*/

//- includes
//-- personnal includes

#include "core/thread.h"

//-- system includes

//- miscellanous

//-- constants

//-- types

//-- class members

//- public

//-- friend functions

//-- methods

int Thread::Start() {
  return pthread_create(& threadId_, 0, Thread::EntryPoint, this);
}

int Thread::Cancel() {
  return pthread_cancel(threadId_);
}

int Thread::Join() {
  return pthread_join(threadId_, 0);
}

//-- class methods

//-- operator overloads

//-- constructors - destructor

/**

*/
Thread::Thread() {

}

/**

*/
Thread::~Thread() {

}

//- protected

//-- methods

//-- static

void * Thread::EntryPoint(void * pthis) {
  Ptr thread(reinterpret_cast<Thread *>(pthis));
  thread->Run();
  return 0;
}

//- private

//-- methods


