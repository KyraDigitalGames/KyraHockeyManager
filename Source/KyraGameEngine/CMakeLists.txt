add_library(KyraGameEngine STATIC GameState.hpp
                                  GameState.cpp
                                  AbstractGameStateOwner.hpp
                                  AbstractGameStateFactory.hpp
                                  GameStateFactory.hpp
                                  GameStateManager.hpp
                                  GameStateManager.cpp
                                  Application.hpp
                                  Application.cpp)
target_link_libraries(KyraGameEngine PUBLIC sfml-system sfml-window sfml-graphics TGUI::TGUI Database)
target_include_directories(KyraGameEngine PUBLIC ${PROJECT_SOURCE_DIR}/Source)