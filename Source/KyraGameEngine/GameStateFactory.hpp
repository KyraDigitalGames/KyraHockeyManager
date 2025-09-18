#ifndef KYRAGAMEENGINE_GAMESTATEFACTORY_HPP
#define KYRAGAMEENGINE_GAMESTATEFACTORY_HPP

#include "AbstractGameStateFactory.hpp"

namespace kyra {
  
	template<class GameStateType>
	class GameStateFactory : public AbstractGameStateFactory {

	public:

		std::shared_ptr<GameState> create() {
			return std::make_shared<GameStateType>();
		}

	};

}

#endif