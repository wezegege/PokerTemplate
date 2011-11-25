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
#pragma once
#ifndef POKERTEMPLATE_THREADING_ENGINE_H_
#define POKERTEMPLATE_THREADING_ENGINE_H_

#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <vector>

class EngineManager;
class Message;

class Engine {
  public:
    virtual void Initialize() = 0;
    virtual void Execute() = 0;
    virtual void Finalize() = 0;
    void Launch();
    void Receive(boost::shared_ptr<Message> message);

    explicit Engine(EngineManager & engineManager);
    virtual ~Engine() {}
  protected:
    std::vector< boost::shared_ptr<Message> > messages_;
    EngineManager & engineManager_;

  private:
    static void StartThread(Engine * engine);
    boost::shared_ptr<boost::thread> thread_;
};

#endif
