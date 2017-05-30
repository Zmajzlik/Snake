#pragma once
class Game
{
public:
	bool status;
	bool borders;
	int score = 0;
	Game(); // konstruktor
	~Game(); // destruktor
	int render();
	void checkInput();
	void SetWindow(int Width, int Height);
	int getSize();
	void reset();
};