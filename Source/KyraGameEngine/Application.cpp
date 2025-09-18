#include "Application.hpp"

namespace kyra {
  
  GameStateManager& Application::getGameStateManager() {
			return m_GameStateManager;
	}

	int Application::run() {

			auto windowDescriptor = getWindowDescriptor();
			m_Window.create(sf::VideoMode({ windowDescriptor.width, windowDescriptor.height }), windowDescriptor.title);
			m_GUI.setWindow(m_Window);

			if (!init()) {
				return -1;
			}

			while (m_Window.isOpen() && m_GameStateManager.hasActiveGameStates()) {
				while (const std::optional event = m_Window.pollEvent()) {
					if (event->is<sf::Event::Closed>()) {
						m_Window.close();
					}
					m_GUI.handleEvent(*event);
				}
				m_Window.clear();
				m_GUI.draw();
				m_Window.display();
			}

			m_GUI.removeAllWidgets();

			return 0;
		}
}