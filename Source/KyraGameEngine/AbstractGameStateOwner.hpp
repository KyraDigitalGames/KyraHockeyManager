#ifndef KYRAGAMEENGINE_ABSTRACTGAMESTATEOWNER_HPP
#define KYRAGAMEENGINE_ABSTRACTGAMESTATEOWNER_HPP

namespace kyra {
  
	class AbstractGameStateOwner {

	public:

		virtual bool pushGameState(int id) = 0;
		virtual bool popGameState() = 0;
 
	};

}

#endif