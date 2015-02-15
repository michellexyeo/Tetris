#ifndef MANAGER_H
#define MANAGER_H

#include "blocks.h"
#include <vector>

class Manager {
	public: 
		Manager();
		~Manager();

		void generate(int cols_, std::vector<int>& initParams_);
		void tick();
		void draw(WINDOW* win, int x_, int y_, const char _singleBlock);
		void left();
		void right();
	private:
		const char _singleBlock = 'x';
		double _speed;

};

#endif
