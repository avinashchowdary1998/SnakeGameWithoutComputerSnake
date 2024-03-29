# CPPND: Capstone Snake Game Example

<img src="snake_game.gif"/>

Extended the Snake Game.

Features added to the SnakeGame are :

1.Added 6 obstacles at random position. If the snake hits these obstacles, the game will end.

2.Allowed the user to select the Initial speed either slow or fast. If the user selects slow his/her score increases by 1. If the user selects fasr his/her score increases by 2.

3.Allowed the users to enter their names and saved them in a text file with their scores.

Project Rubric points covered are :

1.The project reads data from a file and process the data or the program writes data to a file - This point is addressed in ScoreFile.cpp file.

2.The Project accepts user input and processes the input - This point is addressed in InitialSpeed.cpp file where I allowed the user to select initial speed.

3.The project uses Object Oriented Programming - I have created new classes like Obstacle class, InitialSpeed class, ScoreFile class etc.

4.Classes use appropriate access specifiers for class members - In the classes mentioned in above point, I have used appropriate access specifiers.

5.The Project demonstrates an understanding of C++ functions and control structures - Throughout the project I have implemented various functions and have used various control structures.

6.Class constructors uses member initialization lists - In game.cpp file I have initialized InitialSpeed variable using member initialization lists.

7.Classes abstract implementation details from their interfaces - In various classes i have used member functions as interface to the class.

8.Classes encaptulate behaviour - In the three classes that i have built, I have grouped appropriate data and functions into one class. I have used member functions to access private data.


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
