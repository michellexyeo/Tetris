#include "manager.h"
#include <cstdlib>
#include <iostream>

Manager::Manager(int rows_, int cols_) 
	: _rows(rows_), _cols(cols_)
{
	_singleBlock = 'x';
	_shape = 0;
	_orientation = 0;
	_deadShape = true;
}

Manager::~Manager() {}

void Manager::begin(WINDOW* win_) {
	generate();
	draw(win_, 1, _startPos);
}

void Manager::generate() {
	_startPos = rand() % _cols;
	_x = _startPos;
	_y = 1;
	_shape = rand() % 7;
	_orientation = rand() % 4;
}

void Manager::tick(WINDOW* win_) {
	if (_deadShape) {
		begin(win_);
		_deadShape = false;
	}
	draw(win_, ++_y, _x);			
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
	++_x;
	if (_x > _cols) {
		_x = _cols;
	}
	return;
}

void Manager::right() {
	--_x;
	if (_x < 1) {
		_x = 1;
	}
	return;
}

void Manager::rotate() {
	++_orientation;
	_orientation %= 4;	
}

bool Manager::getDeadShape() {
	return _deadShape;
}

void Manager::setDeadShape(bool dead_) {
	_deadShape = dead_;
}
