/**
 * @author Kevin TRAN
 * @version 0.1
 * @date 16/02/2011
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
 * Header for class Engine
 *  
 * @section HISTORY
 *
 * 16/02/2011 : first draft
 */
 
#ifndef ##PROJECT##_ENGINE_H_
#define ##PROJECT##_ENGINE_H_

//- includes
//-- personnal includes

#include "core/threadManager.h"

//-- system includes

#include <boost/shared_ptr.hpp>

//-- forward declarations

/**

*/
public class Engine : public ThreadManager {
//- public
public:
//-- typedefs and enums

//-- constants
	
//-- methods
	/**
	 * 
	 * @param thread
	 */
	virtual void Create(boost::shared_ptr<Thread> thread);
	
	/**
	 * 
	 * @param index
	 */
	virtual void Join(int index);
	
	/**
	 * 
	 */      
	virtual void Destroy();
	
//-- operator overloads

//-- constructors - destructor
	/**
	 * default constructor
	 */
	Engine();

	/**
	 * Destructor
	 */
	~Engine();


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
	 * @param aEngine the value of the assignment
	 * @return a reference to itself
	 */
	Engine & operator=(const Engine & aEngine);
	
	/**
	 * copy constructor
	 * @param aEngine the value of the assignment
	 */
	explicit Engine(const & Engine aEngine);
	
//-- data members

	boost::shared_ptr<Thread> thread;

} // class Engine

//- nonmember functions

//- inline and template definitions file include
//#include "Engine.tpp"

#endif // ##PROJECT##_ENGINE_H_