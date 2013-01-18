cmake_minimum_required(VERSION 2.6)
project(Main CXX)

#add_definitions(-g -O2 -fsigned-char -freg-struct-return -Wall -W -Wshadow -Wstrict-prototypes -Wpointer-arith -Wcast-qual -Winline -Werror)

add_subdirectory(Artemis-Cpp)

file(GLOB components "components/*.cc")
file(GLOB systems "systems/*.cc")
set(files ${components} ${systems})
add_executable(Main main.cc entity_factory.cc ${files})

target_link_libraries(Main Artemis)
