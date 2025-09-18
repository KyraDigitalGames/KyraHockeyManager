#ifndef KYRAHOCKEYMANAGER_GAMESTATES_INTROGAMESTATE_HPP
#define KYRAHOCKEYMANAGER_GAMESTATES_INTROGAMESTATE_HPP

#include <KyraGameEngine/GameState.hpp>

namespace khm {
  
  class IntroGameState : public kyra::GameState {

  public:

    static constexpr int Id = 1;

    bool init(tgui::Gui& gui) final;

  };

}

#endif