/**
 * @author Kevin TRAN
 * @version 0.1
 * @date 14/02/2011
 * @section LICENSE
 *
 * This file is part of £PROJECT£.
 * 
 * £PROJECT£ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * £PROJECT£ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with £PROJECT£.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Header for class ThreadManager
 *  
 * @section HISTORY
 *
 * 14/02/2011 : first draft
 */
 
#ifndef £PROJECT£_THREADMANAGER_H_
#define £PROJECT£_THREADMANAGER_H_

//- includes
//-- personnal includes

//-- system includes

//-- forward declarations

class Thread;

namespace boost {
	template<typename T>
	class shared_ptr<T>;
}

/**

*/
public class ThreadManager {
//- public
public:
//-- typedefs and enums

//-- constants
	
//-- methods
	/**
	 * 
	 * @param thread
	 */
	virtual void Create(boost::shared_ptr<Thread> thread) = 0;
	
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

	/**
	 * Destructor
	 */
	~ThreadManager();


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
	explicit ThreadManager(const & ThreadManager aThreadManager);
	
//-- data members

} // class ThreadManager

//- nonmember functions

//- inline and template definitions file include
//#include "ThreadManager.tpp"

#endif // £PROJECT£_THREADMANAGER_H_