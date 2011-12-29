/**
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
 */

#include "engine.h"
using boost::shared_ptr;
using boost::thread;

#include "../message/message.h"

void Engine::Launch() {
  thread_ = shared_ptr<thread>(new thread(Engine::StartThread, this));
}

void Engine::StartThread(Engine * engine) {
  engine->Execute();
}

void Engine::Finalize() {
  thread_->join();
}

void Engine::Receive(shared_ptr<Message> message) {
  messages_.push_back(message);
}

Engine::Engine(EngineManager & engineManager) :
  messages_(),
  engineManager_(engineManager),
  thread_() {}
