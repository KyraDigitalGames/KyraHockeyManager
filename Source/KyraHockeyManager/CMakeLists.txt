add_executable(KyraHockeyManager KyraHockeyManager.cpp
				 ./GameStates/IntroGameState.hpp
				 ./GameStates/IntroGameState.cpp
				 ./GameStates/MainMenuGameState.hpp
				 ./GameStates/MainMenuGameState.cpp)

target_link_libraries(KyraHockeyManager PRIVATE KyraGameEngine)
install(TARGETS KyraHockeyManager RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)