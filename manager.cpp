#include "manager.h"
#include <cstdlib>
#include <iostream>

Manager::Manager() {
	_singleBlock = 'x';
	_shape = 0;
	_orientation = 0;
}

Manager::~Manager() {}

void Manager::generate(int cols_, std::vector<int>& initParams_) {
	int startPos = rand() % cols_;
	_shape = rand() % 7;
	_orientation = rand() % 4;
	//std::vector<int> temp = {startPos, shape, orientation};
	//FINDME why doesn't c++11 initialiser list syntax work?? bloody hell..
	std::vector<int> temp;
	temp.push_back(startPos);
	temp.push_back(_shape);
	temp.push_back(_orientation);
	try {
		initParams_ = std::move(temp);
	} catch (std::exception& e) {
		std::cerr << "Moving of initial params failed." << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void Manager::tick() {

	return;
}

void Manager::draw(WINDOW* win, int y_, int x_) {
	for (size_t i=0; i<4; ++i) {
		for (size_t j=0; j<4; ++j) { if (Blocks[_shape][_orientation][i][j] != 0) {
				wattron(win, A_BOLD | COLOR_PAIR(Blocks[_shape][_orientation][i][j]));
				mvwprintw(win, y_ + i, x_ + j, &_singleBlock);	
				wattroff(win, A_BOLD | COLOR_PAIR(Blocks[_shape][_orientation][i][j]));
			}
		}
	}
	return;
}

void Manager::left() {

	return;
}

void Manager::right() {

	return;
}

void Manager::rotate() {
	++_orientation;
	_orientation %= 4;	
}
