#include "manager.h"
#include <cstdlib>
#include <iostream>

Manager::Manager(int cols_) 
	: _cols(cols_)
{
	_singleBlock = 'x';
	_shape = 0;
	_orientation = 0;
}

Manager::~Manager() {}

void Manager::begin(WINDOW* win_) {
	generate();
	draw(win_, 1, _startPos);
}

void Manager::generate() {
	_startPos = rand() % _cols;
	_shape = rand() % 7;
	_orientation = rand() % 4;
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
