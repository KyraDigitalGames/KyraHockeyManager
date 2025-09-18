#include <KyraGameEngine/Application.hpp>

namespace khm {

	class WorldEditor : public kyra::Application {

	public:

		bool init() final;

		const kyra::WindowDescriptor getWindowDescriptor() const;
		
	};

}