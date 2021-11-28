#pragma once
#include <thread>
#include "Console.h"
#include "Car.h"
#include "Boat.h"
#include "Shark.h"
#include "Map.h"
#include "TrafficLight.h"
#include "people.h"
#include "truck.h"

class Game {
private:
	int dis1 = 0, i1 = 0;
	int dis2 = 0, i2 = 0;
	int dis3 = 0, i3 = 0;
	int dis4 = 0, i4 = 0;
	int dis5 = 0, i5 = 0;
	int dis6 = 0, i6 = 0;
	int dis7 = 0, i7 = 0;

	vector<Boat*>listBoat;
	vector<Shark*>listShark;
	vector<Car*>Carlist1, Carlist2;
	vector<Truck*>Trucklist1, Trucklist2;
	vector<TrafficLight*> ListLight;

	People* p;
	Map* map;
	int point, speed, level, maxlevel;

	void ini();
	void iniBoat();
	void iniShark();
	void iniCar();
	void iniTruck();
	void iniMap();
	void iniTL();
	void iniPeople();

	template<class T>
	void Moving(vector<T*>& obj, int& i, int& dis);

	template<class T>
	void TFcontrol(vector<T*>& obj);
	bool GameOver();

	void p_ingame();

	void ResetGame();
public:

	void RunGame();
};
