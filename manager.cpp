#include "manager.h"
#include <cstdlib>
#include <iostream>

Manager::Manager() {
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

void Manager::draw(WINDOW* win, int y_, int x_, const char _singleBlock) {

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
