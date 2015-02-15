# Makefile for ncurses tetris project
# Author: Michelle Yeo

tetris : main.o manager.o
#		 cc -std=gnu++11 -o tetris main.o manager.o -lncurses
		 clang++ -std=c++11 -stdlib=libc++ -o tetris main.o manager.o -lncurses

main.o : main.cpp blocks.h
		 cc -c main.cpp

manager.o : manager.cpp manager.h blocks.h
			cc -c manager.cpp

clean : 
	rm tetris main.o manager.o
