#include "GameState.hpp"

namespace kyra {
  
 		void GameState::setGameStateOwner(AbstractGameStateOwner* owner) {
			m_Owner = owner;
		}
		
		bool GameState::pushGameState(int id) {
			if (m_Owner) {
				return m_Owner->pushGameState(id);
			}
			return false;
		}

		bool GameState::popGameState() {
			if (m_Owner) {
				return m_Owner->popGameState();
			}
			return false;
		}

}