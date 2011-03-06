/**
 * @author Kevin TRAN
 * @date 06/03/2011
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
 * Header for class ThreadDescriptor
 */

#ifndef POKERTEMPLATE_CORE_THREADDESCRIPTOR_H_
#define POKERTEMPLATE_CORE_THREADDESCRIPTOR_H_

//- includes
//-- personnal includes

//-- system includes

#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

//-- forward declarations

class ThreadManager;
namespace boost {
  namespace program_options {
    class options_description;
  }
}

/**

*/
class ThreadDescriptor {
  //- public
  public:
    //-- typedefs and enums
typedef std::vector<ThreadDescriptor> Vector;
    //-- constants

    //-- methods

    /**
     *
     * @return
     */
    virtual boost::shared_ptr<ThreadManager> GetManager() const;

    /**
     *
     * @return
     */
    virtual boost::program_options::options_description GetOptions() const;

    /**
     *
     * @return
     */
    virtual boost::program_options::options_description GetHiddenOptions() const;

/**
 *
 * @return 
 */
    const std::string & GetName() const;

    //-- operator overloads

    //-- constructors - destructor
    /**
     * default constructor
     */
    ThreadDescriptor();

    /*

     * Destructor
     */
    virtual ~ThreadDescriptor();


    //- protected
  protected:
    //-- typedefs and enums

    //-- constants

    //-- methods

    /**
     *
     * @return
     */
    boost::shared_ptr<ThreadManager> GetModule() const;

    /**
     *
     * @return
     */
    boost::shared_ptr<ThreadManager> GetEngine() const;

    //-- data members

    //- private
  private:
    //-- typedefs and enums

    //-- constants

    //-- methods

    /**
     * assignment operator overload
     * @param aThreadDescriptor the value of the assignment
     * @return a reference to itself
     */
    ThreadDescriptor & operator=(const ThreadDescriptor & aThreadDescriptor);

    /**
     * copy constructor
     * @param aThreadDescriptor the value of the assignment
     */
    explicit ThreadDescriptor(const ThreadDescriptor & aThreadDescriptor);

    //-- data members

  const std::string name_;

}; // class ThreadDescriptor

//- nonmember functions

//- inline and template definitions file include
//#include "core/threadDescriptor-inl.h"

#endif // POKERTEMPLATE_CORE_THREADDESCRIPTOR_H_

