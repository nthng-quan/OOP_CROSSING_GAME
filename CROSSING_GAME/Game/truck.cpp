#include "truck.h"

void Truck::DRAW() {
	COORD position = pos;
	for (int i = 0; i < height; i++) {
		GotoXY({ position.X, position.Y++ });
		for (int j = 0; j < width; j++) {
			if (position.X + j >= 21 && position.X + j <= 108)
				cout << graphic[i][j];
		}
	}
}
bool Truck::isMoving()
{
	return state;
}

int Truck::getWidth() {
	return width;
}

void Truck::Moving() {
	if (!state)
	{
		state = true;
		return;
	}

	if (pos.X + width >= 110 + 21 + 1 || pos.X + width <= 21 + 10 + 1) {
		del(pos, { pos.X + width, pos.Y + height });
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
		if(pos.X <= 110 - 21 -1)
		del(pos, { pos.X + width ,pos.Y + height });
		pos.X--;
	}

	DRAW();
}