# Makefile for ncurses tetris project
# Author: Michelle Yeo

tetris : main.o
		 cc -o tetris main.o

main.o : main.cpp
		 cc -c main.cpp

clean : rm tetris main.o
