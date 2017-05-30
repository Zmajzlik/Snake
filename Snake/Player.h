#pragma once
class Player
{
public:
	int posX;
	int posY;
	int speedX;
	int speedY;

	Player(); // konstruktor
	~Player(); // destruktor 
	void setPosition(int x, int y);
	void draw();
};