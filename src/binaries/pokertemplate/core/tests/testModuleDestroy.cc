/**
* @author Kevin TRAN
* @date 03/03/2011
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
* Main entry.
*/

//- includes
//-- personnal includes
#include "core/thread.h"
#include "core/module.h"
//-- system includes
#include <iostream>
using std::cout;
using std::endl;
#include <cstdlib>

class NeverEndingThread : public Thread {
  public:
    int Run() {
      for(;;);
      return 0;
    }
};

/**
*
*/
int main(int argc, char** argv) {
  Module module;
  Thread::Ptr thread1(new NeverEndingThread());
  Thread::Ptr thread2(new NeverEndingThread());
  module.Create(thread1);
  module.Create(thread2);
  module.Destroy();

return EXIT_SUCCESS;
}

