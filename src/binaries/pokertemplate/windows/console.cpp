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

#include "windows/console.h"
#include <gtkmm/stock.h>
#include <gtkmm/box.h>

void Console::Initialize() {
  // Result view
  resultView_.set_wrap_mode(Gtk::WRAP_WORD);
  resultView_.set_editable(false);

  // Command entry
  commandEntry_.signal_activate().connect(sigc::mem_fun(this, &Console::Submit));
  // Submit button
  submitBtn_.set_can_focus(false);
  submitBtn_.signal_clicked().connect(sigc::mem_fun(this, &Console::Submit));

  // Horizontal Align
  Gtk::HBox * hAlign = new Gtk::HBox();
  hAlign->pack_start(commandEntry_);
  hAlign->pack_start(submitBtn_, Gtk::PACK_SHRINK);

  // Vertical Align
  Gtk::VBox * vAlign = new Gtk::VBox();
  vAlign->pack_start(resultView_);
  vAlign->pack_start(*manage(hAlign), Gtk::PACK_SHRINK);

  // Window Settings
  add(*manage(vAlign));
  set_focus_child(commandEntry_);
  show_all();
}

void Console::Submit() {
  std::string command = commandEntry_.get_text();
  buffer_->insert_at_cursor(command + "\n");
  commandEntry_.set_text("");
}

Console::Console() :
  submitBtn_(Gtk::Stock::OK),
  commandEntry_(),
  resultView_(),
  buffer_(resultView_.get_buffer()) {
  Initialize();
}
