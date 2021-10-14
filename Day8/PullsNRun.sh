#!/bin/bash
echo "Pulling..."
git pull origin master
echo "OK"
echo "Compile..."
g++ ~/projects/CppBootCamp/Assignments/Day2/LinkedList/LinkedList.cpp -o ~/projects/CppBootCamp/Assignments/Day2/LinkedList/a.out
echo "OK"
echo "Execute..."
~/projects/CppBootCamp/Assignments/Day2/LinkedList/a.out
echo "OK"

