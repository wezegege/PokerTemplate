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

#include "widgets/chat.h"
using std::string;

using Gtk::TextIter;
using Gtk::Button;
using Gtk::TextBuffer;
using sigc::mem_fun;
using Glib::RefPtr;
#include "utils/time.h"
#include <gtkmm/stock.h>
#include <gtkmm/box.h>
using Gtk::HBox;
#include <gtkmm/scrolledwindow.h>
using Gtk::ScrolledWindow;
#include <gtkmm/buttonbox.h>
using Gtk::HButtonBox;

void Chat::Initialize() {
  createTags();
  setWidgets();
}

void Chat::ShowUsers() {
  users_.set_visible(!users_.get_visible());
}

void Chat::Submit() {
  string command = commandEntry_.get_text();
  Write("Admin", command);
  commandEntry_.set_text("");
}

void Chat::Write(string name, string content) {
  TextIter iter = buffer_->end();
  buffer_->create_mark("begin", iter);
  // time
  if(showTimestamp_) {
    buffer_->insert_at_cursor("[" + Time::Now() + "]");
  }

  // name
  iter = buffer_->end();
  buffer_->create_mark("beginName", iter);
  buffer_->insert_at_cursor("[" + name + "]:");
  TextIter beginIter = buffer_->get_iter_at_mark(buffer_->get_mark("beginName"));
  iter = buffer_->end();
  buffer_->apply_tag_by_name("User", beginIter, iter);

  //content
  buffer_->insert_at_cursor(content);
  beginIter = buffer_->get_iter_at_mark(buffer_->get_mark("begin"));
  iter = buffer_->end();
  buffer_->apply_tag_by_name("System", beginIter, iter);
  resultView_.scroll_to(iter);
  buffer_->insert_at_cursor("\n");
}

Chat::Chat() :
  showTimestamp_(true),
  submitBtn_(Gtk::Stock::OK),
  commandEntry_(),
  resultView_(),
  buffer_(resultView_.get_buffer()),
  users_(1),
  showUsersBtn_("show users") {
    Initialize();
  }

void Chat::setWidgets() {
  // Show user button
  showUsersBtn_.set_can_focus(false);
  showUsersBtn_.signal_clicked().connect(mem_fun(this, &Chat::ShowUsers));

  // First level
  HButtonBox * firstLvl = new HButtonBox(Gtk::BUTTONBOX_END);
  firstLvl->pack_start(showUsersBtn_);

  // Result view
  resultView_.set_wrap_mode(Gtk::WRAP_WORD);
  resultView_.set_editable(false);

  ScrolledWindow * messageScroll = new Gtk::ScrolledWindow();
  messageScroll->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  messageScroll->add(resultView_);

  // User list
  users_.set_column_title(0, "Users");
  users_.set_headers_visible(false);
  users_.append("Admin");
  users_.append("Console");

  ScrolledWindow * userScroll = new ScrolledWindow();
  userScroll->set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
  userScroll->add(users_);

  // Second level
  HBox * secondLvl = new HBox();
  secondLvl->pack_start(*manage(messageScroll));
  secondLvl->pack_start(*manage(userScroll), Gtk::PACK_SHRINK);

  // Command entry
  commandEntry_.signal_activate().connect(mem_fun(this, &Chat::Submit));

  // Submit button
  submitBtn_.set_can_focus(false);
  submitBtn_.signal_clicked().connect(mem_fun(this, &Chat::Submit));

  // Third level
  HBox * thirdLvl = new HBox();
  thirdLvl->pack_start(commandEntry_);
  thirdLvl->pack_start(submitBtn_, Gtk::PACK_SHRINK);

  // Vertical Align
  pack_start(*manage(firstLvl), Gtk::PACK_SHRINK);
  pack_start(*manage(secondLvl));
  pack_start(*manage(thirdLvl), Gtk::PACK_SHRINK);

  // Window Settings
  set_focus_child(commandEntry_);
}

void Chat::createTags() {
  buffer_->create_tag("User");

  Glib::RefPtr<TextBuffer::Tag> tag = buffer_->create_tag("System");
  tag->property_foreground() = "orange";
}

