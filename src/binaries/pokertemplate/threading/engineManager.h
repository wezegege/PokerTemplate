/** * @section LICENSE
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
#pragma once
#ifndef POKERTEMPLATE_THREADING_THREADMANAGER_H_
#define POKERTEMPLATE_THREADING_THREADMANAGER_H_

#include "engine.h"
#include "../message/message.h"
#include <boost/shared_ptr.hpp>
#include <vector>


class EngineManager {
  public:
    enum Type {SERVER, CLIENT, BOT, MAINWINDOW};
    int AddEngine(Type type, boost::shared_ptr<Engine> engine);
    void Initialize();
    void Finish();
    void Send(boost::shared_ptr<Message> message);
    EngineManager() : engines_() {}
  private:
    typedef std::vector< boost::shared_ptr<Engine> > EngineStreet;
    typedef std::vector<EngineStreet> EngineCity;
    EngineCity engines_;
};
#endif
