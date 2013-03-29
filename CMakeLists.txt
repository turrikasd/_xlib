cmake_minimum_required (VERSION 2.6)
project (_xlib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Add src directory to the search path for includes
include_directories("${PROJECT_SOURCE_DIR}/src")

# Add the src directory as path for CMakeLists.txt
add_subdirectory(src)
