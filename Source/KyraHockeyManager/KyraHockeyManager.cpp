#include "KyraHockeyManager.hpp"
#include <KyraHockeyManager/GameStates/MainMenuGameState.hpp>
#include <KyraHockeyManager/GameStates/IntroGameState.hpp>


namespace khm {
  
    bool KyraHockeyManager::init() {
      kyra::GameStateManager& gameStateManager = getGameStateManager();
      gameStateManager.registerGameState<IntroGameState>(IntroGameState::Id);
      gameStateManager.registerGameState<MainMenuGameState>(MainMenuGameState::Id);
      gameStateManager.pushGameState(IntroGameState::Id);
      return true;
    }

    const kyra::WindowDescriptor KyraHockeyManager::getWindowDescriptor() const {
      kyra::WindowDescriptor windowDescriptor;
      windowDescriptor.title = "Kyra Hockey Manager";
      windowDescriptor.width = 800;
      windowDescriptor.height = 600;
      return windowDescriptor;
    }
}

int main(int argc, char** argv) {
	return khm::KyraHockeyManager().run();
}