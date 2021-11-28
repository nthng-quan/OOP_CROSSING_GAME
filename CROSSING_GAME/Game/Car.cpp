#include "Car.h"

void Car::DRAW() {
	COORD position = pos;
	for (int i = 0; i < height; i++) {
		GotoXY({ position.X, position.Y++ });
		for (int j = 0; j < width; j++) {
			if (position.X + j >= 15 && position.X + j <= 108) // 108 -> edge 15 : width
				cout << graphic[i][j];
		}
	}
}
bool Car::isMoving()
{
	return state;
}

int Car::getWidth() {
	return width;
}

void Car::Moving() {
	if (!state)
	{
		state = true;
		return;
	}

	if (pos.X + width >= 110 + 15 + 1 || pos.X + width <= 15 + 1)
	{
		del(pos, { pos.X + width , pos.Y + height});
		state = false;
		pos = inpos;
	
		return;
	}

	if (state and direction)
	{	
		del(pos, { pos.X + 1, pos.Y + height });
		pos.X++;
	}

	if (state and !direction)
	{
		if(pos.X <= 110 - 15 - 1)
			del(pos, { pos.X + width, pos.Y + height });
		pos.X--;
	}

	DRAW();
}


//char*Car::backup() {
//	COORD position = pos;
//	char* a = new char[height];
//	for (int i = 0; i < height; i++) 
//		a[i] = GetCOORD({ position.X + width+1, position.Y++});
//	return a;
//	
//}
//
//void Car::DRAWBU(const char *a) {
//	COORD position = pos;
//	for (int i = 0; i < height; i++) {
//		GotoXY({ position.X - 1,position.Y++ });
//		cout << a[i];
//	}
//}