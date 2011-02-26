/**
 * @author Kevin TRAN
 * @version 0.1
 * @date 14/02/2011
 * @section LICENSE
 *
 * This file is part of ##PROJECT##.
 * 
 * ##PROJECT## is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * ##PROJECT## is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with ##PROJECT##.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Header for class Thread
 *  
 * @section HISTORY
 *
 * 14/02/2011 : first draft
 */
 
#ifndef ##PROJECT##_THREAD_H_
#define ##PROJECT##_THREAD_H_

//- includes
//-- personnal includes

#include "message/messageBox.h"

#include "core/threadManager.h"

//-- system includes

#include <boost/weak_ptr>

//-- forward declarations

/**

*/
template<typename TM>
public class Thread<TM> {
//- public
public:
//-- typedefs and enums

//-- constants
	
//-- methods
	
	/**
	 * Entry point for new thread creating
	 */
	virtual void Run() = 0;

	/**
	 * Delegate method for messageBox.ReceiveMessage()
	 */
	void ReceiveMessage();
	
	
	/**
	 
	 */
	virtual void ExitThread();
	
	/**
	 
	 */
	static void Destroy();
	
//-- operator overloads

//-- constructors - destructor

	/**
	 * Destructor
	 */
	~Thread();


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
	 * @param aThread the value of the assignment
	 * @return a reference to itself
	 */
	Thread & operator=(const Thread & aThread);

	/**
	 * default constructor
	 */
	Thread();
	
	/**
	 * copy constructor
	 * @param aThread the value of the assignment
	 */
	explicit Thread(const & Thread aThread);
	
//-- data members

	MessageBox messageBox; ///< permits other threads to send messages to this one

	static TM threadManager;
	
} // class Thread

//- nonmember functions

//- inline and template definitions file include
//#include "Thread.tpp"

#endif // ##PROJECT##_THREAD_H_