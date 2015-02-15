#ifndef MANAGER_H
#define MANAGER_H

#include "blocks.h"
#include <vector>

class Manager {
	Manager();
	~Manager();

	void generate(int cols_, std::vector<int>& initParams_);
};

#endif
