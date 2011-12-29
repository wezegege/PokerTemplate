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

#include "engineManager.h"
using boost::shared_ptr;
#include "../message/message.h"

void EngineManager::Initialize() {
  for (int i = 0; i < 4; ++i) {
    engines_.push_back(EngineStreet());
  }
}

int EngineManager::AddEngine(Type type, boost::shared_ptr<Engine> engine) {
  engine->Launch();
  int engineId = engines_.at(type).size();
  engines_.at(type).push_back(engine);
  return engineId;
}

void EngineManager::Finish() {
  for (EngineCity::iterator cityIt = engines_.begin();
      cityIt != engines_.end(); ++cityIt) {
    for (EngineStreet::iterator streetIt = cityIt->begin();
        streetIt != cityIt->end(); ++streetIt) {
      (*streetIt)->Finalize();
    }
  }
}

void EngineManager::Send(shared_ptr<Message> message) {
  engines_.at(message->Type()).at(message->Number())->Receive(message);
}
