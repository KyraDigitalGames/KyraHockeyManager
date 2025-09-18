message(STATUS "Fetching Cereal 1.3.2")

SET(SKIP_PERFORMANCE_COMPARISON ON CACHE BOOL "Skip building performance sandbox comparison (requires boost)" FORCE)


FetchContent_Declare(
  cereal
  GIT_REPOSITORY https://github.com/USCiLab/cereal.git
  GIT_TAG        v1.3.2
)

FetchContent_MakeAvailable(cereal)