#ifndef MANAGER_H
#define MANAGER_H

#include "blocks.h"
#include <vector>
#include <ncurses.h>

class Manager {
	public: 
		Manager();
		~Manager();

		void generate(int cols_, std::vector<int>& initParams_);
		void tick();
		void draw(WINDOW* win, int y_, int x_, const char _singleBlock);
		void left();
		void right();
		void rotate();
	private:
		const char _singleBlock = 'x';
		double _speed;
		int _shape;
		int _orientation;

};

#endif
