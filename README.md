# Catane

This project consists in the videogame adaptation of the board game **Les Colons de Catane**. Each player takes turns on the same computer.

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

* Windows - Download the adequate zip archive *cmocka-1.1.0-mingw.zip*, at the address https://cmocka.org/files/1.1/, then follow the installation instructions.

##### SDL2 library

* Linux - Type this command in a terminal: 
```
sudo apt-get install libsdl2-dev
```

* Windows - Download the adequate zip archive, Development Libraries category, at the address https://www.libsdl.org/download-2.0.php, then follow the installation instructions.

##### SDL2-ttf library

* Linux - Type this command in a terminal: 
```
sudo apt-get install libsdl2-ttf-dev
```

* Windows - Download the adequate zip archive, Development Libraries category, at the address https://www.libsdl.org/projects/SDL_ttf/, then follow the installation instructions.

##### CMake build system

* Linux - Type this command in a terminal: 
```
sudo apt-get install cmake
```

* Windows - Download the adequate zip archive, à l'adresse https://cmake.org/download/, then follow the installation instructions.

### Building

A step by step series of examples that tell you how to get the executable files

In the catane directory, generate the *Makefile* 

```
cmake .
```

Then build the binaries in the *bin* directory

```
make all
```

Now you have two binaries in the *bin* directory : *catane_tests* for testing purposes, and *catane* for running purposes.

## Running the tests

To run the model tests, in the *bin* directory, run the *catane_tests* executable.

## Built With

* [Code::Blocks](http://www.codeblocks.org/) - The IDE used
* [CMake](https://cmake.org/) - Build system
* [SDL](https://www.libsdl.org/index.php) - Graphical library used

## Authors

* **Emmanuel Durel** 
* **Rémi Fargeon**
* **Titouan Gaborit**
* **Pauline Manauthon**
