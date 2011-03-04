/**
* @author Kevin TRAN
* @date 04/03/2011
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
* Header for class Container
*/

#ifndef POKERTEMPLATE_CORE_CONTAINER_H_
#define POKERTEMPLATE_CORE_CONTAINER_H_

//- includes
//-- personnal includes

#include "core/settingManager.h"

//-- system includes

//-- forward declarations

/**

*/
class Container {
//- public
public:
//-- typedefs and enums

//-- constants

//-- methods
/**
*
*/
void InitParameters(int argc, char ** argv);

/**
*
*/
void InitResources();

/**
*
*/
void InitThreads();


//-- operator overloads

//-- constructors - destructor
/**
* default constructor
*/
Container();

/*

* Destructor
*/
virtual ~Container();


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
* @param aContainer the value of the assignment
* @return a reference to itself
*/
Container & operator=(const Container & aContainer);

/**
* copy constructor
* @param aContainer the value of the assignment
*/
explicit Container(const Container & aContainer);

//-- data members

  SettingManager settingManager_;

}; // class Container

//- nonmember functions

//- inline and template definitions file include
//#include "container-inl.h"

#endif // POKERTEMPLATE_CORE_CONTAINER_H_

