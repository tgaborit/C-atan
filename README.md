# Catane

  This project consists in the videoludic adaptation of the board game **Les Colons de Catane**, as part of our studies in the Electronics and Computer Engineering department,
at the INSA Rennes engineering school.
It follows the rules of the original board game, and each player takes turns on the same computer.

![screenshot](documents/screenshot.png)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for running and testing purposes.

### Prerequisites

What things you need to install the software and how to install them

##### CMocka library

* Linux - Type this command in a terminal: 
```
sudo apt-get install libcmocka-dev
```

* Windows - Download the adequate zip archive *cmocka-1.1.0-mingw.zip*, at the address https://cmocka.org/files/1.1/. Then follow the installation instructions.

##### SDL2 library

* Linux - Type this command in a terminal: 
```
sudo apt-get install libsdl2-dev
```

* Windows - Download the adequate zip archive, Development Libraries category, at the address https://www.libsdl.org/download-2.0.php. Then follow the installation instructions.

##### SDL2-ttf library

* Linux - Type this command in a terminal: 
```
sudo apt-get install libsdl2-ttf-dev
```

* Windows - Download the adequate zip archive, Development Libraries category, at the address https://www.libsdl.org/projects/SDL_ttf/. Then follow the installation instructions.

##### CMake build system

* Linux - Type this command in a terminal: 
```
sudo apt-get install cmake
```

* Windows - Download the adequate zip archive, à l'adresse https://cmake.org/download/. Then follow the installation instructions.

### Building

A step by step series of examples that tell you how to get the executable files

In the project root directory, generate the *Makefile* 

```
cmake .
```

Then build the binaries in the `/bin` directory (not the OS one but relating to the project root)

```
make all
```

Now you have two binaries in the `/bin` directory : *catane_tests* for testing purposes, and *catane* for running purposes.

## Running the tests

To run the model tests, in the `/bin` directory, run the *catane_tests* executable.

## Tree view

* `/modele` : the headers and sources files relating to the model part of the project
* `/vue` : the headers and sources files relating to the view part of the project
* `/controleur` : the headers and sources files relating to the controller part of the project
* `/images` : the images necesary for the project
* `/fonts` : the fonts necesary for the project
* `/tests` : the headers and sources files relating to the tests of the model part of the project
* `/cmake` : the CMake script to find the SDL2-ttf library
* `/documents` : the documents used for the project management

## Built With

* [Code::Blocks](http://www.codeblocks.org/) - The IDE used
* [CMake](https://cmake.org/) - Build system
* [SDL](https://www.libsdl.org/index.php) - Graphical library used
* [CMocka](https://cmocka.org/) - Test library used
* [Valgrind](http://www.valgrind.org/) - For detecting memory leaks

## Authors

* **Emmanuel Durel** 
* **Rémi Fargeon**
* **Titouan Gaborit**
* **Pauline Manauthon**
