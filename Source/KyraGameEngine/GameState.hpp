#ifndef KYRAGAMEENGINE_GAMESTATE_HPP
#define KYRAGAMEENGINE_GAMESTATE_HPP

#include "AbstractGameStateOwner.hpp"
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

namespace kyra {
  
	class GameState {

		AbstractGameStateOwner* m_Owner = nullptr;

	public:
		virtual ~GameState() = default;

		virtual bool init(tgui::Gui& gui) = 0;

		void setGameStateOwner(AbstractGameStateOwner* owner);
		
		bool pushGameState(int id);

		bool popGameState();

	};

}

#endif