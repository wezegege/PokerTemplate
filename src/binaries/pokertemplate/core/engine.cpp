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
 * implementation of class Engine
 */

//- includes
//-- personnal includes

#include "core/engine.h"

//-- system includes

//- miscellanous

//-- constants

//-- types

//-- class members

//- public

//-- friend functions

//-- methods

void Engine::Create(Thread::Ptr thread) 
  throw(WrongThreadException, UniqueThreadException) {
  if(thread == 0) {
    throw WrongThreadException();
  }
  if(thread_ != 0) {
    throw UniqueThreadException();
  }
  thread->Start();
  thread_ = thread;
}

void Engine::Join(int) throw(NoThreadException) {
  if(thread_ == 0) {
    throw NoThreadException();
  }
  thread_->Join();
}

void Engine::Destroy() throw(NoThreadException) {
  if(thread_ == 0) {
    throw NoThreadException();
  }
  thread_->Cancel();
}

//-- class methods

//-- operator overloads

//-- constructors - destructor

/**

*/
Engine::Engine() {

}

/**

*/
Engine::~Engine() {

}

//- protected

//-- methods

//- private

//-- methods

