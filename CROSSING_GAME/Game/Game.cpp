#include "Game.h"
// 1 : L -> R
// 0 : R -> L

void Game::ini() {
	speed = 100;
	level = point = 0;
	maxlevel = 10;
}

void Game::iniBoat() {
	if (!listBoat.empty()) {
		for (auto e : listBoat) {
			delete e;
		}
	}
	listBoat.clear();
	for (int i = 0; i < 3; i++) {
		listBoat.push_back(new Boat({ 101 ,20 }, 26, 4, "graphic/boat1.txt", 0, 0));
	}
}

void Game::iniShark() {
	if (!listShark.empty()) {
		for (auto e : listShark) {
			delete e;
		}
	}

	listShark.clear();
	for (int i = 0; i < 3; i++) {
		listShark.push_back(new Shark({ 11 ,36 }, 25, 5, "graphic/shark.txt", 1, 0));
	}
}

void Game::iniCar() {
	if (!Carlist1.empty()) {
		for (auto e : Carlist1) {
			delete e;
		}
	}

	if (!Carlist2.empty()) { 
		for (auto e : Carlist2) {
			delete e;
		}
	}

	Carlist1.clear();
	Carlist2.clear();

	for (int i = 0; i < 3; i++) {
		// MAP_START_POS = 11;
		// LINE_NO_2 = 10
		Carlist1.push_back(new Car({ 11, 10 }, 15, 3, "graphic/car.txt", 1, 0));
		// LINE_NO_5 = 26
		Carlist2.push_back(new Car({ 11, 26 }, 15, 3, "graphic/car.txt", 1, 0));
	}
}

void Game::iniTruck() {

	if (!Trucklist1.empty()) {
		for (auto e : Trucklist1) {
			delete e;
		}
	}

	if (!Trucklist2.empty()) {
		for (auto e : Trucklist2) {
			delete e;
		}
	}

	Trucklist1.clear();
	Trucklist2.clear();

	for (int i = 0; i < 3; i++) {
		Trucklist1.push_back(new Truck({ 110 ,15 }, 21, 3, "graphic/truck.txt", 0, 0));
		Trucklist2.push_back(new Truck({ 110 ,31 }, 21, 3, "graphic/truck.txt", 0, 0));
	}
}

void Game::iniMap() {
	if (map != nullptr)
		delete map;

	map = new Map({ 10,5 }, 101 + 26, 41, "graphic/map1.txt");
}

void Game::iniPeople() {
	if (p != nullptr)
		delete p;

	p = new People({ 56,42 }, 3, 3, "graphic/people.txt", 0);
}

void Game::iniTL() {
	if (!ListLight.empty())
		for (auto e : ListLight)
			delete e;
	ListLight.clear();

	ListLight.push_back(new TrafficLight({ 15,12 }, 3, 3, "graphic/TrafficL.txt", 0));
	ListLight.push_back(new TrafficLight({ 105,28 }, 3, 3, "graphic/TrafficL.txt", 0));
}

template<class T>
void Game::Moving(vector<T*>& obj, int& i, int& dis) {
	srand(time(0));
	for (int j = 0; j < obj.size(); j++)
		if (obj[j]->isMoving())obj[j]->Moving();

	if (i == 0) {
		obj[i]->Moving();
		i++;
	}

	if (dis >= obj[i - 1]->getWidth() + (rand() % 60))
	{
		if (i == obj.size())i = 0;
		else obj[i]->Moving(), i++;

		dis = 0;
	}
	else dis++;
}

template<class T>
void Game::TFcontrol(vector<T*>& obj) {
	for (int i = 0; i < 2; i++)
	{
		ListLight[i]->ControlTraffic();
	}
}

bool Game::GameOver() {
	if (p->IsDead())
		return true;
	return false;
}

void Game::p_ingame() {
	p->Moving(*map);
	if (p->IsOnTop())
	{
		speed -= 10;
		level++;
		point = level * 100;
		p->Get_Start();
	}
}

void Game::RunGame() {
	ResetGame();
	map->DRAW();
	while (!GameOver()) {
		p_ingame();
		TFcontrol(ListLight);
		
		if (!ListLight[0]->GetState()) {
			Moving(Carlist1, i1, dis1);
			Moving(Trucklist1, i2, dis2);
		}
		
		Moving(listBoat, i3, dis3);

		if (!ListLight[1]->GetState()) {
			Moving(Carlist2, i4, dis4);
			Moving(Trucklist2, i5, dis5);
		}

		Moving(listShark, i7, dis7);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WORD(11));
		GotoXY({ 116,21 });
		cout << "> LEVEL: " << level << "/" << maxlevel;
		GotoXY({ 116,22 });
		cout << "> SCORE: " << point;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WORD(15));

		Sleep(speed);
	}
}

void Game::ResetGame() {
	ini();

	iniMap();

	iniTruck();
	iniCar();
	iniShark();
	iniBoat();

	iniPeople();
	iniTL();
}