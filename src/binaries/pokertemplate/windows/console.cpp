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

#include "console.h"

void Console::Initialize() {
  setWidgets();
}

Console::Console() :
  width_(300), height_(400), title_("Console"),
  chat_() {
  Initialize();
}

void Console::setWidgets() {
  set_default_size(width_, height_);
  set_title(title_);
  set_position(Gtk::WIN_POS_CENTER);
  add(chat_);
  //show_all();
  set_focus_child(chat_);
}
