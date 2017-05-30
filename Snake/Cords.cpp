#include "stdafx.h"
#include "Cords.h"
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void Cords::gotoXY(int x, int y) {
	//Inicjalizacja koordynatow
	COORD coord = { x, y };
	//Ustawienia pozycji
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

void Cords::getCursorXY(int &x, int&y) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		x = csbi.dwCursorPosition.X;
		y = csbi.dwCursorPosition.Y;
	}
}