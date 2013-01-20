# README

Author: Daniel "MaTachi" Jonsson

## Compile and run

### Dependencies

Building this project with CMake will also compile its dependencies (Allegro 5,
Box2D and the C++ port of Artemis) before linking. Therefore you need to
install all packages required by those projects too. [The ones required by
Allegro 5](http://wiki.allegro.cc/index.php?title=Ubuntu_and_Allegro_5) should
probably be enough.

### Instructions

 1. `mkdir build`
 2. `cd build`
 3. `cmake ..`
 4. `make`
 5. `cd ..`
 5. `./build/Main`

