This project was being made with Guild of Independent Game Authors (GIGA),
but only got to this stage before being redone as a Javascript HTML 5 game. 
I've managed to find the GIGA-uwindsor github again, and have forked the javascript version to my repositories.
You can find it here https://github.com/StephenNu/Spider-Fish.js



Spider Fish
===========

Building with cmake
=======

First, download and install cmake.
    http://www.cmake.org/

Run the following commands:

    $ cd build
    $ cmake ../

This will generate a build system appropriate for your environment in the
`build` directory. Built binaries will be located in `build/bin`.

Running the game Windows
=======

1. Build the game.
2. If on Windows, copy all dlls from `lib` to the same directory as the
   `spifi_game` executable. 
3. Copy images into the same directory as the executable, or if using 
	Visual Studios copy the images into the project directory.
4. Run the `spifi_game` executable in `build/bin`.

Linux
=======

Prerequisites
-------
1. libsdl1.2
3. libsdl-ttf2.0
5. libsdl-image1.2
7. libsdl-mixer1.2
8. libsdl-gfx
9. cmake
10. make
11. gcc

Build/Run
-------
1. mkdir build
1. cd build
1. cmake ..
1. make
1. ./spifi

Directory structure
=======

* /src - cpp source files
* /resources - images, audio files, etc
