#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

class Taxiservice : public Taxicab
{
public:
	int meter;
	double rate;
	double account;
	bool passanger;
public:
	Taxiservice(string name, double rate)
	{
		this->name = name;
		this->xPosition = 0;
		this->yPosition = 0;
		this->odometer = 0;
		this->meter = 0;
		this->rate = rate;
		this->account = 0;
		this->passanger = false;
	}
	Taxiservice()
	{
		//skibidi ohio fortnie rizz
	}
	void pickUp()
	{
		this->passanger = true;
	}
	void dropOff()
	{
		this->passanger = false;
		account += (this->meter * this->rate);
		this->meter = 0;
	}
	void callTaxi(int beginX, int beginY, int endX, int endY)
	{
		int horzDelta = beginX - this->xPosition;
		if (horzDelta < 0)
			this->moveLeft(horzDelta * -1);
		else
			this->moveRight(horzDelta);
		int vertDelta = beginY - this->yPosition;
		if (vertDelta < 0)
			this->moveDown(vertDelta * -1);
		else
			this->moveUp(vertDelta);
		this->pickUp();
		horzDelta = endX - beginX;
		this->moveRight(horzDelta);
		vertDelta = endY - beginY;
		this->moveUp(vertDelta);
		this->dropOff();
	}
	void display()
	{
		Taxicab::display();
		cout << "Meter: " << this->meter << (this->passanger ? "[P]\n" : "\n")
			<< "Account: " << this->account << endl;
	}
	void moveUp(int distance)
	{
		Taxicab::moveUp(distance);
		if (this->passanger)
			this->meter += distance;
	}
	void moveDown(int distance)
	{
		Taxicab::moveDown(distance);
		if (this->passanger)
			this->meter += distance;
	}
	void moveLeft(int distance)
	{
		Taxicab::moveLeft(distance);
		if (this->passanger)
			this->meter += distance;
	}
	void moveRight(int distance)
	{
		Taxicab::moveRight(distance);
		if (this->passanger)
			this->meter += distance;
	}
};
