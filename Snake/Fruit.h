#pragma once
class Fruit
{
public:
	int x;
	int y;
	Fruit(); // konstruktor
	~Fruit(); // destruktor 
	void setPosition(int x, int y);
	void draw();
};
