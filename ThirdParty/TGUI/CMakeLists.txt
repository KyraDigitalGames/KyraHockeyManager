message(STATUS "Fetching TGUI 1.10.0")

set(TGUI_BACKEND "SFML_GRAPHICS" CACHE STRING "" FORCE)

FetchContent_Declare(
  tgui
  GIT_REPOSITORY https://github.com/texus/TGUI.git
  GIT_TAG        v1.10.0
)

FetchContent_MakeAvailable(tgui)