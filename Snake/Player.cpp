#include "stdafx.h"
#include "Player.h"
#include "Cords.h"
#include <iostream>

using namespace std;

Player::Player()
{
}

Player::~Player()
{
}

void Player::setPosition(int x, int y) {
	posX = x;
	posY = y;
}

void Player::draw() {
	HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	Cords::gotoXY(posX, posY);
	SetConsoleTextAttribute(con, 420);
	cout << (char)254;
	SetConsoleTextAttribute(con, 15);
}