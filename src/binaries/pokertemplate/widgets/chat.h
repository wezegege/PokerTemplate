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
#pragma once
#ifndef POKERTEMPLATE_WIDGETS_CHAT_H_
#define POKERTEMPLATE_WIDGETS_CHAT_H_

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/textbuffer.h>
#include <gtkmm/textview.h>
#include <gtkmm/listviewtext.h>
#include <gtkmm/scrolledwindow.h>

class Chat : public Gtk::VBox {
  public:
    void Initialize();
    void Submit();
    void ShowUsers();
    void ShowSubmit();
    void Write(std::string name, std::string content);

    sigc::signal<void, std::string> signal_message_sent() {
      return signal_message_sent_;
    }

    Chat();

  private:
    void createTags();
    void setWidgets();

    sigc::signal<void, std::string> signal_message_sent_;

    // Parameters
    bool showTimestamp_;

    // Widgets
    Gtk::Button submitBtn_;
    Gtk::Entry commandEntry_;
    Gtk::TextView resultView_;
    Glib::RefPtr<Gtk::TextBuffer> buffer_;
    Gtk::ListViewText users_;
    Gtk::ScrolledWindow  userScroll_;
    Gtk::Button showUsersBtn_;
};

#endif

