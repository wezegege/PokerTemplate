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
 */

#ifndef POKERTEMPLATE_MESSAGE_MESSAGEBOX_H_
#define POKERTEMPLATE_MESSAGE_MESSAGEBOX_H_

#include "message/message.h"

#include <queue>
#include <semaphore.h>
#include <pthread.h>
#include <boost/shared_ptr.hpp>

class MessageBox {
  public:

    MessageBox();

    virtual ~MessageBox();

    /**
     * Read oldest unread message received. Wait for it if there isn't any.
     */
    boost::shared_ptr<Message> ReadMessage();

    /**
     * Post a message to the message box.
     */
    void ReceiveMessage(boost::shared_ptr<Message> message);

  private:

    explicit MessageBox(const MessageBox & aMessageBox);
    MessageBox & operator=(const MessageBox &);

    //-- data members
    std::queue<Message> messages; ///< queue of unread received messages

    sem_t synchroSemaphore_; ///< semaphore for waiting if no message
    pthread_mutex_t readMutex_; ///< message queue lock

}; // class MessageBox

#endif // POKERTEMPLATE_MESSAGE_MESSAGEBOX_H_

