cmake_minimum_required(VERSION 2.8)
project(Main CXX)

#add_definitions(-g -O2 -fsigned-char -freg-struct-return -Wall -W -Wshadow -Wstrict-prototypes -Wpointer-arith -Wcast-qual -Winline -Werror)

add_subdirectory(Artemis-Cpp)
#add_subdirectory(allegro-5.0.8)
#add_subdirectory(Box2D_v2.2.1)


include(ExternalProject)
set(box2d_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/box2d")
set(box2d_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/box2d")
set(box2d_DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/box2d/download")
set(box2d_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${box2d_INSTALL_DIR})

#set(BUILD_SHARED_LIBS ON)
set(BUILD_SHARED_LIBRARIES OFF)

ExternalProject_Add(Box2D
    PREFIX ${box2d_PREFIX}
    URL http://box2d.googlecode.com/files/Box2D_v2.2.1.zip
    INSTALL_DIR ${box2d_INSTALL_DIR}
    CMAKE_ARGS ${box2d_CMAKE_ARGS}
)

set(allegro_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/allegro")
set(allegro_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/allegro")
set(allegro_DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/allegro/download")
set(allegro_CMAKE_ARGS -DSHARED=off -DCMAKE_INSTALL_PREFIX=${allegro_INSTALL_DIR})
#set(allegro_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${allegro_INSTALL_DIR})

ExternalProject_Add(Allegro
    PREFIX ${allegro_PREFIX}
    URL http://sourceforge.net/projects/alleg/files/allegro/5.0.8/allegro-5.0.8.tar.gz/download?utm_expid=65835818-0&utm_referrer=http%3A%2F%2Falleg.sourceforge.net%2Fdownload.html
    INSTALL_DIR ${allegro_INSTALL_DIR}
    CMAKE_ARGS ${allegro_CMAKE_ARGS}
)

# TODO: Add Artemis as ExternalProject
#include(ExternalProject)
#set(artemis_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/artemis")
#set(artemis_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/artemis")
#set(artemis_DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/artemis/download")
#set(artemis_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${artemis_INSTALL_DIR})
#
#ExternalProject_Add(Artemis
#    PREFIX ${artemis_PREFIX}
#    GIT_REPOSITORY git://github.com/MaTachi/sten-och-skrot.git
#    INSTALL_DIR ${artemis_INSTALL_DIR}
#    CMAKE_ARGS ${artemis_CMAKE_ARGS}
#)

# TODO: Needed?
#link_directories(${box2d_INSTALL_DIR})
#add_subdirectory(${box2d_INSTALL_DIR})

file(GLOB components "components/*.cc")
file(GLOB systems "systems/*.cc")
set(files ${components} ${systems})
add_executable(Main main.cc entity_factory.cc ${files})

#target_link_libraries(Main Artemis ${box2d_PREFIX}/lib/libBox2D.a)
#target_link_libraries(Main Artemis ${box2d_PREFIX}/lib/libBox2D.a ${allegro_PREFIX}/lib/liballegro.so ${allegro_PREFIX}/lib/liballegro_image.so)
target_link_libraries(Main Artemis ${box2d_PREFIX}/lib/libBox2D.a ${allegro_PREFIX}/lib/liballegro_image-static.a png z jpeg ${allegro_PREFIX}/lib/liballegro-static.a m pthread SM ICE X11 Xext Xcursor GL GLU Xrandr Xinerama)
# Why are Xrandr and Xinerama needed?

add_dependencies(Main Artemis Box2D)
