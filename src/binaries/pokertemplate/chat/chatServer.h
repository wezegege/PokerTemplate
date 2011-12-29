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
#ifndef POKERTEMPLATE_CHAT_CHATSERVER_H_
#define POKERTEMPLATE_CHAT_CHATSERVER_H_

#include "threading/engine.h"
#include "threading/engineContainer.h"
#include "type.h"

class ChatServer : public Engine {
  public:
    static EngineContainer<ChannelUid> Container;

    ChatServer(ChannelUid channelName);

  private:
    ChannelUid name_;

};

#endif

