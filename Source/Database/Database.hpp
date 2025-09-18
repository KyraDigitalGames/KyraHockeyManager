#ifndef KYRAHOCKEYMANAGER_DATABASE_DATABASE_HPP
#define KYRAHOCKEYMANAGER_DATABASE_DATABASE_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace khm {
	namespace db {
		
		using Id = uint64_t;

		struct Entity {
			Id id;
		};
		
		
		template<typename EntityType>
		class EntityManager {

			std::vector<EntityType> m_Entities;
			std::unordered_map<Id, std::size_t> m_Index;

			Id m_NextId = 1;

		public:
			
			using iterator = typename std::vector<EntityType>::iterator;
			iterator begin() { return m_Entities.begin(); }
			iterator end() { return m_Entities.end(); }

			constexpr Id getNextId() const {
				return m_NextId;
			}

			EntityType* create(EntityType entity) {
				if (entity.id) {
					if (entity.id >= m_NextId) {
						m_NextId = entity.id + 1;
					}
				}
				else {
					entity.id = m_NextId;
					m_NextId++;
				}
				m_Index[entity.id] = m_Entities.size();
				m_Entities.emplace_back(entity);
				return &m_Entities.back();
			}

			EntityType* get(Id id) {
				auto it = m_Index.find(id);
				if (it == m_Index.end()) {
					return nullptr;
				}
				return m_Entities[it->second];
			}

			bool remove(Id id) {
				auto it = m_Index.find(id);
				if (it == m_Index.end()) {
					return false;
				}
				std::size_t index = it->second;
				m_Entities[index] = std::move(m_Entities.back());
				m_Entities.pop_back();
				m_Index[m_Entities[index].id] = index;
				m_Index.erase(it);
				return true;
			}

		};
		
		struct Continent : public Entity {
			std::string name = "";
		};

		class Database {

			EntityManager<Continent> m_ContinentManager;

		public:

			EntityManager<Continent>& getContinentManager() {
				return m_ContinentManager;
			}

		};
	}
}

#endif