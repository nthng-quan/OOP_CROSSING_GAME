#pragma once
#include "Vehicle.h"
class Car :public Vehicle {
public:
	Car(COORD pos_, short width_, short height_, const char* filename, bool direction_, bool state_)
		:Vehicle(pos_, width_, height_, filename, direction_, state_) {};

	void Moving();
	void DRAW();

	int getWidth();

	bool isMoving();

	/*char* backup();
	void DRAWBU(const char*a);*/
};
