rm a.out ; g++ -Wall main.cc components/*.cc systems/*.cc Artemis-Cpp/*.cpp `pkg-config --libs --static allegro-static-5.0` -L /usr/lib -I /usr/include ; ./a.out

g++ -Wall main.cc components/*.cc systems/*.cc Artemis-Cpp/*.cpp `pkg-config --libs --static allegro-static-5.0` -L /usr/local/lib -I /usr/local/include

rm a.out ; g++ -Wall main.cc components/*.cc systems/*.cc Artemis-Cpp/*.cpp `pkg-config --libs --static allegro-static-5.0` -L /usr/local/lib -I /usr/local/include ; ./a.out

rm a.out ; g++ -Wall main.cc components/*.cc systems/*.cc Artemis-Cpp/*.cpp `pkg-config --libs --static allegro-static-5.0 allegro_image-static-5.0` -lBox2D -L/usr/local/lib -I/usr/local/include ; ./a.out
