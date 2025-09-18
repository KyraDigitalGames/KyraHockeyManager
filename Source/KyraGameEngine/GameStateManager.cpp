#include "GameStateManager.hpp"

namespace kyra {
  
  	bool GameStateManager::pushGameState(int id) {
			m_GUI.removeAllWidgets();
			auto it = m_GameStateFactories.find(id);
			if (it != m_GameStateFactories.end()) {
				m_ActiveGameState = it->second->create();
				m_ActiveGameState->setGameStateOwner(this);
				m_ActiveGameState->init(m_GUI);
				return true;
			}
			return false;
		}

		bool GameStateManager::popGameState() {
			if (m_ActiveGameState) {
				m_GUI.removeAllWidgets();
				m_OldGameState = m_ActiveGameState;
				m_ActiveGameState.reset();
				return true;
			}
			return false;
		}

		bool GameStateManager::hasActiveGameStates() const {
			return m_ActiveGameState.get() != nullptr;
		}

}