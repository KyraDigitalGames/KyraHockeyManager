#ifndef KYRAGAMEENGINE_ABSTRACTGAMESTATEFACTORY_HPP
#define KYRAGAMEENGINE_ABSTRACTGAMESTATEFACTORY_HPP

#include "GameState.hpp"
#include <memory>

namespace kyra {
  

	class AbstractGameStateFactory {

	public:
		virtual ~AbstractGameStateFactory() = default;

		virtual std::shared_ptr<GameState> create() = 0;

	};
  
}

#endif