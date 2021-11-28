#pragma once
#include "Console.h"
class Vehicle {
protected:
	short width, height;
	char graphic[30][30];
	COORD inpos, pos;
	bool direction;
	bool state;
private:
public:
	Vehicle();
	Vehicle(COORD pos_, short width_, short height_, const char* filename, bool direction_, bool state_);

	virtual void DRAW() = 0;
	virtual void Moving() = 0;

	virtual int getWidth() = 0;

	virtual bool isMoving() = 0;


	~Vehicle();
};

//template<class T>
//void Moving(vector<T>&obj, int& i, int& dis);
