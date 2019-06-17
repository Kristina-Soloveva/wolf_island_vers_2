#pragma once
#include "Animal.h"

class Bunny : public Animal{
public:
	Bunny() {}
	Bunny(int x, int y):Animal(x,y){}

	~Bunny() {}

};