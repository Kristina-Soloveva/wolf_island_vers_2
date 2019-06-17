#pragma once
#include "Animal.h"
#include "Predator.h"

class She_Wolf : public Predator {
public:
	She_Wolf() {}
	She_Wolf(int x, int y):Predator(x,y) {}
	~She_Wolf() {}

};

