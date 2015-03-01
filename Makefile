# Makefile for ncurses tetris project
# Author: Michelle Yeo

tetris : main.o manager.o scoremaster.o
#		 cc -std=gnu++11 -o tetris main.o manager.o -lncurses
		 clang++ -stdlib=libc++ -std=c++11 -o tetris main.o manager.o scoremaster.o -lpanel -lncurses -Wc++11-extensions 

main.o : main.cpp blocks.h
		 cc -c main.cpp

manager.o : manager.cpp manager.h blocks.h
			cc -c manager.cpp

scoremaster.o : scoremaster.cpp scoremaster.h

clean : 
	rm tetris *.o
