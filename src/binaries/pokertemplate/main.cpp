/**
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
 */

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <cstdlib>
#include <exception>

void ending();
void unexpect();

int main(int argc, char** argv) {
  std::set_terminate(ending);
  std::set_unexpected(unexpect);
  cout << "Hello World !" << endl;

  return EXIT_SUCCESS;
}

void ending() {
  cerr << "Unhandled exception" << endl;
  exit(EXIT_FAILURE);
}

void unexpect() {
  cerr << "Unexpected exception" << endl;
  std::terminate();
};
