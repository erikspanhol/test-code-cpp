cmake_minimum_required(VERSION 3.16)
project(test_code_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(game STATIC
  src/ring_buffer.cpp
  src/inventory.cpp
  src/stats.cpp
)
target_include_directories(game PUBLIC src)

enable_testing()
add_executable(game_tests tests/test_main.cpp)
target_link_libraries(game_tests PRIVATE game)
add_test(NAME game_tests COMMAND game_tests)
