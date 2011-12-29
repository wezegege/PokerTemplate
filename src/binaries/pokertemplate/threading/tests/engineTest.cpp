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
using std::endl;
#include "../engineManager.h"
#include "../engine.h"
using boost::shared_ptr;

class TestEngine : public Engine {
  public:
    void Initialize() {}
    void Execute() {
      cout << "coucou" << endl;
    }
    void Finalize() { Engine::Finalize(); }
    TestEngine(EngineManager  & em) : Engine(em) {}
};

int main() {
  EngineManager engineManager;
  engineManager.Initialize();
  shared_ptr<TestEngine> engine(new TestEngine(engineManager));
  engineManager.AddEngine(EngineManager::SERVER, engine);
  engineManager.Finish();
}
