#include "manager.h"
#include <cstdlib>
#include <iostream>

Manager::Manager() {}

Manager::~Manager() {}

void Manager::generate(int cols_, std::vector<int>& initParams_) {
	int startPos = rand() % cols_;
	int shape = rand() % 7;
	int orientation = rand() % 4;
	//std::vector<int> temp = {startPos, shape, orientation};
	//FINDME why doesn't c++11 initialiser list syntax work?? bloody hell..
	std::vector<int> temp;
	temp.push_back(startPos);
	temp.push_back(shape);
	temp.push_back(orientation);
	try {
		initParams_ = std::move(temp);
	} catch (std::exception& e) {
		std::cerr << "Moving of initial params failed." << std::endl;
		std::cerr << e.what() << std::endl;
	}
}
