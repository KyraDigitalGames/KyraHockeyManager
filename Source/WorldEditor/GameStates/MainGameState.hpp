#ifndef WORLDEDITOR_GAMESTATES_MAINGAMESTATE_HPP
#define WORLDEDITOR_GAMESTATES_MAINGAMESTATE_HPP

#include <KyraGameEngine/GameState.hpp>
#include <Database/Database.hpp>

namespace khm {


	class AbstractContentView {

	public:
		virtual ~AbstractContentView() = default;

		virtual bool init(tgui::Panel::Ptr panel, db::Database& database) = 0;

	};

	class ContentContainer {

		tgui::Panel::Ptr m_Panel;
		db::Database* m_Database = nullptr;

	public:

		bool init(tgui::Gui& gui, db::Database* database) {
			m_Database = database;
			m_Panel = tgui::Panel::create();
			gui.add(m_Panel);
			return true;
		}
		
		void setSize(const std::string& x, const std::string& y) {
			m_Panel->setSize({x.c_str(), y.c_str()});
		}

		void setPosition(const std::string& w, const std::string& h) {
			m_Panel->setPosition({ w.c_str(), h.c_str() });
		}

		template<class ContentViewType>
		void setView() {
			m_Panel->removeAllWidgets();
			ContentViewType().init(m_Panel, *m_Database);
		}

		void reset() {
			m_Panel.reset();
		}

	};

	class ContinentContentView : public AbstractContentView {

	public:

		virtual bool init(tgui::Panel::Ptr panel, db::Database& database) final {
			tgui::ListView::Ptr listView = tgui::ListView::create();
			listView->setSize("100%", "95%");
			listView->addColumn("Id");
			listView->addColumn("Name", 120);
			auto& continentManager = database.getContinentManager();
			for (auto& continent : continentManager) {
				listView->addItem({ std::to_string(continent.id), continent.name});
			}
			panel->add(listView);
			return true;
		}

	};

	class NationContentView : public AbstractContentView {

	public:

		virtual bool init(tgui::Panel::Ptr panel, db::Database& database) final {
			tgui::ListView::Ptr listView = tgui::ListView::create();
			listView->setSize("100%", "95%");
			panel->add(listView);
			return true;
		}

	};

	class MainGameState : public kyra::GameState {

		ContentContainer m_ContentContainer;
		db::Database m_Database;

	public:

		static constexpr int Id = 1;

		bool init(tgui::Gui& gui) final;

	};

}

#endif