#pragma once
#ifndef MENU_H
#define MENU_H
#include "stdafx.h"
#include "Game.h"
#include "Cords.h"
#include <cstdlib>
#include <iostream>

using namespace std;
int m = 1;
Game gra;
void menu()
{
	gra.render();
	cout << "SNAKE" << endl;
	cout << "1. START" << endl;
	cout << "2. STEROWANIE" << endl;
	cout << "3. KRAWEDZIE ON/OFF" << endl;
	cout << "4. Autorzy" << endl;
	cout << "5. WYJDZ" << endl;
	cout << "Wybor: ";
	cin >> m;
	switch (m)
	{
	case 1: {
		gra.status = true;
		while (gra.status)
		{
			cout << "Wynik: " << gra.render();
		}
		Cords::gotoXY(0, gra.getSize() + 2);
		gra.reset();
		cout << "Koniec Gry";
		system("pause > nul");
		menu();
		break;
	}
	case 2: {
		gra.render();
		cout << "WSAD - sterowanie" << endl;
		cout << "Q - wyjscie";
		system("pause > nul");
		menu();
		break;
	}
	case 3: {
		gra.borders = !gra.borders;
		menu();
		break;
	}
	case 4: {
		cout << "Autorami gry sa:" << endl;
		cout << "\t Patrycjusz Suchanek";
		cout << "\n \t Artur Ulfig" << endl;
		system("pause > nul");
		menu();
		break;
	}
	}
}
#endif MENU_H