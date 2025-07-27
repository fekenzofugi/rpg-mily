#!/bin/bash

echo "Compiling SFML project..."

# Compile each .cpp file to .o (object files)
g++ -std=c++17 -c src/main.cpp
g++ -std=c++17 -c src/Game.cpp

# Link all .o files with SFML libraries
g++ main.o Game.o -o prog -lsfml-graphics -lsfml-window -lsfml-system

echo "Done! Run with: ./sfml-app"
