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
 * Header for class Thread
 */

#ifndef POKERTEMPLATE_CORE_THREAD_H_
#define POKERTEMPLATE_CORE_THREAD_H_

//- includes
//-- personnal includes

//-- system includes
#include <boost/shared_ptr.hpp>
#include <pthread.h>

//-- forward declarations

/**

*/
class Thread {
  //- public
  public:
    //-- typedefs and enums
    /// pointer to a thread
    typedef boost::shared_ptr<Thread> Ptr;

    //-- constants

    //-- methods

    /**
     * Provides the means to create the thread and start it going.
     * @return result of the thread creation code
     */
    int Start();

    /**
     *
     */
    int Cancel();

    /**
     *
     */
    int Join();

    //-- operator overloads

    //-- constructors - destructor
    /**
     * default constructor
     */
    Thread();

    /*

     * Destructor
     */
    virtual ~Thread();


    //- protected
  protected:
    //-- typedefs and enums

    //-- constants

    //-- methods

    /**
     *
     */
    virtual int Run() = 0;

    /**
     * This function serves as the entry point to the thread. 
     * It simply casts pthis to Thread * and calls its run method.
     * @param pthis pointer to the thread class to launch
     * @return exit status of the thread id exited
     */
    static void * EntryPoint(void * pthis);


    //-- data members

    //- private
  private:
    //-- typedefs and enums

    //-- constants

    //-- methods

    /**
     * assignment operator overload
     * @param aThread the value of the assignment
     * @return a reference to itself
     */
    Thread & operator=(const Thread & aThread);

    /**
     * copy constructor
     * @param aThread the value of the assignment
     */
    explicit Thread(const Thread & aThread);

    //-- data members

    pthread_t threadId_; ///< Id of the thread if created

}; // class Thread

//- nonmember functions

//- inline and template definitions file include
//#include "thread-inl.h"

#endif // POKERTEMPLATE_CORE_THREAD_H_

