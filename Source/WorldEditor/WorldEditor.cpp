
#include "WorldEditor.hpp"
#include "GameStates/MainGameState.hpp"

namespace khm {

	bool WorldEditor::init() {
		kyra::GameStateManager& gameStateManager = getGameStateManager();
		gameStateManager.registerGameState<MainGameState>(MainGameState::Id);
		gameStateManager.pushGameState(MainGameState::Id);
		return true;
	}

	const kyra::WindowDescriptor WorldEditor::getWindowDescriptor() const {
		kyra::WindowDescriptor windowDescriptor;
		windowDescriptor.title = "Kyra Hockey Manager - World Editor";
		windowDescriptor.width = 1280;
		windowDescriptor.height = 720;
		return windowDescriptor;
	}

}

int main(int argc, char** argv) {
	return khm::WorldEditor().run();
}