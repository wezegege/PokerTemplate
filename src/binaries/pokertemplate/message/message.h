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
* Header for class Message
*/

#ifndef POKERTEMPLATE_MESSAGE_MESSAGE_H_
#define POKERTEMPLATE_MESSAGE_MESSAGE_H_

//- includes
//-- personnal includes

//-- system includes

//-- forward declarations

/**

*/
class Message {
//- public
public:
//-- typedefs and enums

//-- constants

//-- methods
/**
*
* @param
* @return
*/

//-- operator overloads

//-- constructors - destructor
/**
* default constructor
*/
Message();


/**
* copy constructor
* @param aMessage the value of the assignment
*/
//explicit Message(const Message & aMessage);

/*

* Destructor
*/
virtual ~Message();


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
* @param aMessage the value of the assignment
* @return a reference to itself
*/
Message & operator=(const Message & aMessage);

//-- data members

}; // class Message

//- nonmember functions

//- inline and template definitions file include
//#include "message-inl.h"

#endif // POKERTEMPLATE_MESSAGE_MESSAGE_H_

