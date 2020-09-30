cmake_minimum_required(VERSION 3.17)
project(ElaboratoN7_)

set(EXECUTABLE_NAME ElaboratoN7_)

set(CMAKE_CXX_STANDARD 17)

add_executable(ElaboratoN7 Mappa.h Mappa.cpp MapSearchNode.h MapSearchNode.cpp stlastar.h main.cpp fsa.h display.h display.cpp character.h character.cpp Goal.h Goal.cpp Tile.cpp Tile.h)

set(SOURCE_FILE Mappa.h Mappa.cpp MapSearchNode.h MapSearchNode.cpp stlastar.h main.cpp fsa.h display.h display.cpp character.h character.cpp Goal.h Goal.cpp Tile.cpp Tile.h)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH} ${CMAKE_SOURCE_DIR}/SFML-2.5.1/lib")
set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1/include")

set(SFML_ROOT "C:/Users/giuliabellini/Desktop/ElaboratoN7_/SFML-2.5.1")
set(SFML_DIR "${SFML_ROOT_PREFIX}/lib/cmake/SFML")
#set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML COMPONENTS audio graphics network system window REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ElaboratoN7 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

#set(CMAKE_EXE_LINKER_FLAGS "-Xlinker -v -v")
#target_compile_options(ElaboratoN7 PRIVATE -v)

include_directories(${gtest_SOURCE_DIR}/include $gtest_SOURCE_DIR}../include)
add_subdirectory(/Users/giuliabellini/Desktop/ElaboratoN7_/TEST)
add_library(core ${SOURCE_FILE})
target_link_libraries(ElaboratoN7 core)