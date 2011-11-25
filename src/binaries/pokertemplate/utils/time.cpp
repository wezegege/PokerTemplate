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

#include "utils/time.h"
using std::string;
#include <ctime>

string Time::Now(bool seconds, bool twelves) {
  const int BUFFER_SIZE = 20;
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[BUFFER_SIZE];
  string format = "%H:%M";

  if(twelves) {
    if(seconds) {
      format = "%I:%M:%S%p";
    } else {
      format = "%I:%M%p";
    }
  } else if(seconds) {
    format = "%H:%M:%S";
  }

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer, BUFFER_SIZE, format.c_str(), timeinfo);
  return string(buffer);
}

