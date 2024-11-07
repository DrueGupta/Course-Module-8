#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

class Taxiservice : public Taxicab 
{
private:
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
		this-> passanger = false;
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
};
