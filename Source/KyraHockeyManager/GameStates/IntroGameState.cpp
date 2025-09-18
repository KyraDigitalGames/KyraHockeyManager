
#include "IntroGameState.hpp"
#include "MainMenuGameState.hpp"

namespace khm {
  
  bool IntroGameState::init(tgui::Gui& gui) {
      tgui::Button::Ptr button = tgui::Button::create("Hello World");
      button->setPosition({ 100,100 });
      button->setSize({ 100,20 });
      button->onClick([&]() {
        popGameState();
        pushGameState(MainMenuGameState::Id);
      });
      gui.add(button);
      return true;
  }
  
}