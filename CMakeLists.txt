cmake_minimum_required(VERSION 2.6)
project("Pac-Woman")

add_definitions("-std=c++11")

# Define sources
set (SRC src/main.cpp
        src/Game.cpp
        src/GameState.cpp)

# Define executable
set(EXECUTABLE_NAME "pacwoman")
add_executable(${EXECUTABLE_NAME} ${SRC})


# add_executable(pacwoman ${SRC})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# target_link_libraries( pacwoman sfml-system)
# target_link_libraries( pacwoman sfml-window)
# target_link_libraries( pacwoman sfml-graphics)
# target_link_libraries( pacwoman sfml-audio)
# target_link_libraries( pacwoman sfml-network)