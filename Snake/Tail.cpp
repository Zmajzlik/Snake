#include "stdafx.h"
#include "Tail.h"
#include "Cords.h"
#include <iostream>

using namespace std;

Tail::Tail(int x, int y)
{
	setPosition(x, y);
}

Tail::~Tail()
{
}

void Tail::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void Tail::draw() {
	HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	Cords::gotoXY(x, y);
	SetConsoleTextAttribute(con, 10);
	cout << (char)254;
	SetConsoleTextAttribute(con, 15);
}