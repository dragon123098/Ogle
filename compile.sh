#!/bin/bash

brew install sfml
g++ main.cpp -o Adventure -lsfml-system -lsfml-graphics -lsfml-window
./Adventure
