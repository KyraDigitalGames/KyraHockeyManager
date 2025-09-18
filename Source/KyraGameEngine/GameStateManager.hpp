#ifndef KYRAGAMEENGINE_GAMESTATEMANAGER_HPP
#define KYRAGAMEENGINE_GAMESTATEMANAGER_HPP

#include "GameStateFactory.hpp"
#include "AbstractGameStateOwner.hpp"
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <memory>
#include <unordered_map>


namespace kyra {

 	class GameStateManager : public AbstractGameStateOwner {

		tgui::Gui& m_GUI;
		std::shared_ptr<GameState> m_ActiveGameState;
		std::shared_ptr<GameState> m_OldGameState;
		std::unordered_map<int, std::unique_ptr<AbstractGameStateFactory>> m_GameStateFactories;

	public:
		GameStateManager(tgui::Gui& gui) : m_GUI(gui) {

		}

		template<class GameStateType>
		void registerGameState(int id) {
			m_GameStateFactories[id] = std::make_unique<GameStateFactory<GameStateType>>();
		}

		bool pushGameState(int id);

		bool popGameState();

		bool hasActiveGameStates() const;

	};


}

#endif