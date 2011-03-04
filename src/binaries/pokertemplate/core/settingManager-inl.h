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
 * implementation of class SettingManager
 */

//- includes
//-- personnal includes

//-- system includes

//- miscellanous

//-- constants

//-- types

//-- class members

//- public
//-- friend functions

//-- inline methods

//-- template methods
template<typename T>
void SettingManager::SetSetting(std::string settingName, T value) {
  data_[settingName].SetValue(value);
}
template<typename T>
T SettingManager::GetSetting(std::string settingName) {
  return data_[settingName].GetValue<T>();
}

template<typename T>
void Setting::SetValue(T value) {
  value_ = value; 
}

template<typename T>
T Setting::GetValue() {
  return boost::any_cast<T>(value_);
}
//-- operator overloads

//-- constructors - destructor
  template<typename T>
Setting::Setting(std::string label, std::string description, 
    std::string shortcut, T value) 
: shortcut_(shortcut), label_(label), 
  description_(description), shortcut_(shortcut) {

  }
//- protected
//-- methods

//- private
//-- methods
