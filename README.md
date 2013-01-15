# README

Author: Daniel "MaTachi" Jonsson

## Clone project

Since Artemis is included as a submodule, cloning my project requires:

 1. `git clone https://github.com/MaTachi/sten-och-skrot.git`
 2. `git submodule init`
 3. `git submodule update`

## Set up

Below are some things you need to have installed/set up before you are able
to compile my project.

### CheckInstall instead of 'make install'

* [CheckInstall](https://help.ubuntu.com/community/CheckInstall)

### Allegro 5

 * [How to set up Allegro for static linking](https://ventilatorxor.wordpress.com/2011/08/07/linux-allegro5-static-linking-for-beginners/)
 * [Set up Allegro 5 on Ubuntu](http://wiki.allegro.cc/index.php?title=Ubuntu_and_Allegro_5)

### Box2D

 * [Box2D 2.1.2](http://code.google.com/p/box2d/downloads/detail?name=Box2D_v2.1.2.zip&can=2&q=)
 * [My own problems with compiling and running Box2D](http://www.box2d.org/forum/viewtopic.php?f=7&t=9056)

### Artemis

 * [C++ port of Artemis](https://github.com/vinova/Artemis-Cpp)

Note, already included as a [git submodule](http://git-scm.com/book/en/Git-Tools-Submodules).

## Compile project

    rm a.out ; g++ -Wall main.cc components/*.cc systems/*.cc Artemis-Cpp/*.cpp `pkg-config --libs --static allegro-static-5.0 allegro_image-static-5.0` -lBox2D -L/usr/local/lib -I/usr/local/include ; ./a.out
