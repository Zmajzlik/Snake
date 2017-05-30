#include "Game.h"
#include "Cords.h"
#include "Player.h"
#include "Fruit.h"
#include "Tail.h"
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

Player glowa;
Fruit owoc;
const int rozmiarPlanszy = 30;
Tail* ogon[rozmiarPlanszy*rozmiarPlanszy];
int dlugoscOgona = 0;

Game::Game()
{
	srand(time(NULL));
	status = false;
	glowa.setPosition(10, 10);
	glowa.speedX = -1;
	glowa.speedY = 0;
	owoc.setPosition(rand() % (rozmiarPlanszy - 1) + 1, rand() % (rozmiarPlanszy - 2) + 1);
	ogon[0] = new Tail(glowa.posX, glowa.posY);
}

Game::~Game()
{
}

int Game::render() {
	if (glowa.speedX != 0) Sleep(1000 / 12);

	if (glowa.speedY != 0) Sleep(1000 / 8);
	system("cls");
	if (borders)
	{
		for (int i = 0; i < rozmiarPlanszy; i++)
		{
			Cords::gotoXY(0, i);
			cout << (char)219;
			Cords::gotoXY(rozmiarPlanszy, i);
			cout << (char)219;
			Cords::gotoXY(i, 0);
			cout << (char)219;
			Cords::gotoXY(i, rozmiarPlanszy - 1);
			cout << (char)219;
		}
	}
	else {
		for (int i = 0; i < rozmiarPlanszy; i++)
		{
			Cords::gotoXY(0, i);
			cout << (char)176;
			Cords::gotoXY(rozmiarPlanszy, i);
			cout << (char)176;
			Cords::gotoXY(i, 0);
			cout << (char)176;
			Cords::gotoXY(i, rozmiarPlanszy - 1);
			cout << (char)176;
		}
	}
	if (status)
	{
		if (glowa.posX == owoc.x && glowa.posY == owoc.y)
		{
			owoc.setPosition(rand() % (rozmiarPlanszy - 1) + 1, rand() % (rozmiarPlanszy - 2) + 1);
			dlugoscOgona++;
			score += 9;
			ogon[dlugoscOgona] = new Tail(ogon[dlugoscOgona - 1]->x - glowa.speedX, ogon[dlugoscOgona - 1]->y - glowa.speedY);
		}

		//rusz

		ogon[0]->setPosition(glowa.posX, glowa.posY);
		if (borders)
		{
			if (glowa.posX == rozmiarPlanszy - 1 && glowa.speedX == 1) {
				status = false;
			}
			else if (glowa.posX == 1 && glowa.speedX == -1) {
				status = false;
			}
			else if (glowa.posY == rozmiarPlanszy - 2 && glowa.speedY == 1)
			{
				status = false;
			}
			else if (glowa.posY == 1 && glowa.speedY == -1) {
				status = false;
			}
			else {
				glowa.setPosition(glowa.posX + glowa.speedX, glowa.posY + glowa.speedY);
			}
		}
		else {
			if (glowa.posX == rozmiarPlanszy - 1 && glowa.speedX == 1) {
				glowa.setPosition(1, glowa.posY);
			}
			else if (glowa.posX == 1 && glowa.speedX == -1) {
				glowa.setPosition(rozmiarPlanszy - 1, glowa.posY);
			}
			else if (glowa.posY == rozmiarPlanszy - 2 && glowa.speedY == 1)
			{
				glowa.setPosition(glowa.posX, 1);
			}
			else if (glowa.posY == 1 && glowa.speedY == -1) {
				glowa.setPosition(glowa.posX, rozmiarPlanszy - 2);
			}
			else {
				glowa.setPosition(glowa.posX + glowa.speedX, glowa.posY + glowa.speedY);
			}
		}
	}
	//rysuj
	owoc.draw();
	glowa.draw();
	for (int i = dlugoscOgona; i > 0; i--)
	{
		ogon[i]->setPosition(ogon[i - 1]->x, ogon[i - 1]->y);
		ogon[i]->draw();
	}
	Cords::gotoXY(0, 31);
	for (int i = 1; i < dlugoscOgona; i++)
	{
		if (glowa.posX == ogon[i]->x && glowa.posY == ogon[i]->y) {
			status = false;
			return score;
		}
	}

	checkInput();

	return score;
}

void Game::checkInput() {
	if (_kbhit()) {
		char key = _getch();
		switch (key) {
		case 'a': {
			if (glowa.speedX != 1)
			{
				glowa.speedX = -1;
				glowa.speedY = 0;
			}
			return;
		}
		case 'A': {
			if (glowa.speedX != 1)
			{
				glowa.speedX = -1;
				glowa.speedY = 0;
			}
			return;
		}
		case 's': {
			if (glowa.speedY != -1)
			{
				glowa.speedX = 0;
				glowa.speedY = 1;
			}
			return;
		}
		case 'S': {
			if (glowa.speedY != -1)
			{
				glowa.speedX = 0;
				glowa.speedY = 1;
			}
			return;
		}
		case 'w': {
			if (glowa.speedY != 1)
			{
				glowa.speedX = 0;
				glowa.speedY = -1;
			}
			return;
		}
		case 'W': {
			if (glowa.speedY != 1)
			{
				glowa.speedX = 0;
				glowa.speedY = -1;
			}
			return;
		}
		case 'd': {
			if (glowa.speedX != -1)
			{
				glowa.speedX = 1;
				glowa.speedY = 0;
			}
			return;
		}
		case 'D': {
			if (glowa.speedX != -1)
			{
				glowa.speedX = 1;
				glowa.speedY = 0;
			}
			return;
		}
		case 'b': {
			dlugoscOgona++;
			ogon[dlugoscOgona] = new Tail(ogon[dlugoscOgona - 1]->x - glowa.speedX, ogon[dlugoscOgona - 1]->y - glowa.speedY);
			break;
		}
		case 'q':
		case 'Q':
		{status = false; break;
		default:
			break;
		}
		}
	}
}

int Game::getSize() {
	return rozmiarPlanszy;
}
void Game::reset() {
	score = 0;

	for (int i = 0; i < dlugoscOgona; i++)
	{
		delete ogon[i];
		ogon[i] = nullptr;
	}
	dlugoscOgona = 0;
	Game();
}