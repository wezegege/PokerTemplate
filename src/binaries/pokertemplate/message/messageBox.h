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
 * Header for class MessageBox
 */

#ifndef POKERTEMPLATE_MESSAGE_MESSAGEBOX_H_
#define POKERTEMPLATE_MESSAGE_MESSAGEBOX_H_

//- includes
//-- personnal includes
#include "message/message.h"

//-- system includes

#include <queue>
#include <semaphore.h>
#include <pthread.h>
#include <boost/shared_ptr.hpp>
//-- forward declarations

/**

*/
class MessageBox {
  //- public
  public:
    //-- typedefs and enums

    //-- constants

    //-- methods
    /**
     * Read oldest unread message received. Wait for it if there isn't any.
     * @return read message
     */
    boost::shared_ptr<Message> ReadMessage();

    /**
     * Post a message to the message box.
     * @param message the message to post.
     */
    void ReceiveMessage(boost::shared_ptr<Message> message);


    //-- operator overloads

    //-- constructors - destructor
    /**
     * default constructor
     */
    MessageBox();

    /*

     * Destructor
     */
    virtual ~MessageBox();


    //- protected
  protected:
    //-- typedefs and enums

    //-- constants

    //-- methods

    //-- data members

    //- private
  private:
    //-- typedefs and enums

    //-- constants

    //-- methods

    /**
     * assignment operator overload
     * @param aMessageBox the value of the assignment
     * @return a reference to itself
     */
    MessageBox & operator=(const MessageBox & aMessageBox);

    /**
     * copy constructor
     * @param aMessageBox the value of the assignment
     */
    explicit MessageBox(const MessageBox & aMessageBox);

    //-- data members
    std::queue<Message> messages; ///< queue of unread received messages

    sem_t synchroSemaphore_; ///< semaphore for waiting if no message
    pthread_mutex_t readMutex_; ///< message queue lock


}; // class MessageBox

//- nonmember functions

//- inline and template definitions file include
//#include "messageBox-inl.h"

#endif // POKERTEMPLATE_MESSAGE_MESSAGEBOX_H_

