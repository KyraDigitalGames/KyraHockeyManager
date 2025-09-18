#ifndef KYRAHOCKEYMANAGER_GAMESTATES_MAINMENUGAMESTATE_HPP
#define KYRAHOCKEYMANAGER_GAMESTATES_MAINMENUGAMESTATE_HPP

#include <KyraGameEngine/GameState.hpp>

namespace khm {
  
  class MainMenuGameState : public kyra::GameState {

  public:

    static constexpr int Id = 2;

    bool init(tgui::Gui& gui) final;

  };
 
}

#endif