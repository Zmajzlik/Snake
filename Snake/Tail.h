#pragma once
class Tail
{
public:
	int x;
	int y;

	Tail(int x, int y); // konstruktor 
	~Tail(); // destruktor
	void setPosition(int x, int y);
	void draw();
};