add_executable(WorldEditor WorldEditor.cpp
                           WorldEditor.hpp
                           ./GameStates/MainGameState.hpp
                           ./GameStates/MainGameState.cpp)
                           
target_link_libraries(WorldEditor PRIVATE KyraGameEngine)
install(TARGETS WorldEditor RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)