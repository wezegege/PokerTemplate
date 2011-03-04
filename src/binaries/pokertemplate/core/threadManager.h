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
 * Header for class ThreadManager
 */

#ifndef POKERTEMPLATE_CORE_THREADMANAGER_H_
#define POKERTEMPLATE_CORE_THREADMANAGER_H_

//- includes
//-- personnal includes
#include "core/thread.h"

//-- system includes

//-- forward declarations

/**

*/
class ThreadManager {
  //- public
  public:
    //-- typedefs and enums
class NoThreadException {};

    class WrongThreadException {};

    class UniqueThreadException {};

    //-- constants

    //-- methods
    /**
     *
     * @param thread
     */
    virtual void Create(Thread::Ptr thread) = 0;

    /**
     *
     * @param index
     */
    virtual void Join(int index) = 0;

    /**
     *
     */
    virtual void Destroy() = 0;

    //-- operator overloads

    //-- constructors - destructor
    /**
     * default constructor
     */
    ThreadManager();

    /*

     * Destructor
     */
    virtual ~ThreadManager();


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
     * @param aThreadManager the value of the assignment
     * @return a reference to itself
     */
    ThreadManager & operator=(const ThreadManager & aThreadManager);

    /**
     * copy constructor
     * @param aThreadManager the value of the assignment
     */
    explicit ThreadManager(const ThreadManager & aThreadManager);

    //-- data members

}; // class ThreadManager

//- nonmember functions

//- inline and template definitions file include
//#include "threadManager-inl.h"

#endif // POKERTEMPLATE_CORE_THREADMANAGER_H_

