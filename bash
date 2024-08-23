#!/bin/bash

make clean
clear
make
echo -e "\n Enter the mod to run: '--normal' or '--test'"
read mod
./ss $mod
