#include "MainGameState.hpp"

namespace khm {

	bool MainGameState::init(tgui::Gui& gui) {

		auto& continentManager = m_Database.getContinentManager();

		db::Continent continent;
		continent.id = 1;
		continent.name = "Africa";
		continentManager.create(continent);

		continent.id = 2;
		continent.name = "Asia";
		continentManager.create(continent);

		continent.id = 3;
		continent.name = "Europe";
		continentManager.create(continent);



		tgui::MenuBar::Ptr menuBar = tgui::MenuBar::create();
		menuBar->setSize({ "100%", "3%" });
		menuBar->addMenu("File");
		menuBar->addMenuItem("New");
		menuBar->addMenuItem("Load");
		menuBar->addMenuItem("Save");
		menuBar->addMenuItem("Quit");
		menuBar->addMenu("View");
		menuBar->addMenuItem("Continent");
		menuBar->addMenuItem("Nation");
		menuBar->addMenuItem("Region");
		menuBar->addMenuItem("City");
		menuBar->addMenuItem("Team");
		menuBar->addMenuItem("Arena");
		menuBar->addMenuItem("Competition");
		menuBar->addMenuItem("Referees");
		menuBar->addMenuItem("Derbies");
		menuBar->addMenuItem("Sponsors");
		menuBar->addMenuItem("Investors / Investor Groups");
		menuBar->addMenu("Debug");
		menuBar->addMenuItem("Check Database");

		menuBar->onMenuItemClick([&](const std::vector<tgui::String>& menuItem) {
			if (menuItem.size() == 2 && menuItem[0] == "File" && menuItem[1] == "Quit") {
				popGameState();
			} else if (menuItem.size() == 2 && menuItem[0] == "View" && menuItem[1] == "Continent") {
				m_ContentContainer.setView<ContinentContentView>();
			} else if (menuItem.size() == 2 && menuItem[0] == "View" && menuItem[1] == "Nation") {
				m_ContentContainer.setView<NationContentView>();
			}
		   }
		);
		
		gui.add(menuBar);

		m_ContentContainer.init(gui, &m_Database);
		m_ContentContainer.setPosition("0%", "3%");
		m_ContentContainer.setSize("100%", "97%");
		return true;
	}

}