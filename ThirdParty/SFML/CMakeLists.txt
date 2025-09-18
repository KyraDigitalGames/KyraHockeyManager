message(STATUS "Fetching SFML 3.0.2")

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        3.0.2
)

FetchContent_MakeAvailable(sfml)