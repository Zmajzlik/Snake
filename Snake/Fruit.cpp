#include "stdafx.h"
#include "Fruit.h"
#include "Cords.h"
#include <iostream>

using namespace std;

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}

void Fruit::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}
// rysowanie
void Fruit::draw() {
	HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	Cords::gotoXY(x, y);
	SetConsoleTextAttribute(con, 12);
	cout << (char)2;
	SetConsoleTextAttribute(con, 15);
}