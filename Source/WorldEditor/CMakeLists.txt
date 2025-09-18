add_executable(WorldEditor WorldEditor.cpp)
target_link_libraries(WorldEditor PRIVATE sfml-system sfml-window sfml-graphics TGUI::TGUI)
install(TARGETS WorldEditor RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)