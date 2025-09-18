#ifndef KYRAGAMEENGINE_APPLICATION_HPP
#define KYRAGAMEENGINE_APPLICATION_HPP

#include "GameStateManager.hpp"
#include <SFML/Graphics.hpp>
#include <string>

namespace kyra {

	struct WindowDescriptor {
		std::string title = "Kyra Game Engine";
		unsigned int width = 800;
		unsigned int height = 600;
	};

	class Application {

		sf::RenderWindow m_Window;
		tgui::Gui m_GUI;
		GameStateManager m_GameStateManager = { m_GUI };

	public:
		virtual ~Application() = default;

		GameStateManager& getGameStateManager();

		virtual bool init() = 0;
		virtual const WindowDescriptor getWindowDescriptor() const = 0;

		int run();

	};

}

#endif