#ifndef TAXICOMPANY_H
#define TAXICOMPANY_H
#include <iostream>
using namespace std;

class Taxicab
{
protected:
	string name;
	int xPosition = 0;
	int yPosition = 0;
	int odometer;
public:
	Taxicab(string name, int xPosition, int yPosition)
	{
		this->name = name;
		this->xPosition = xPosition;
		this->yPosition = yPosition;
		this->odometer = 0;
	}
	Taxicab() : Taxicab("", 0, 0) {}

	int getX()
	{
		return this->xPosition;
	}
	int getY()
	{
		return this->yPosition;
	}
	int getOdometer()
	{
		return this->odometer;
	}
	void moveUp(int distance)
	{
		this->yPosition += distance;
		this->odometer += distance;
	}
	void moveDown(int distance)
	{
		this->yPosition -= distance;
		this->odometer += distance;
	}
	void moveLeft(int distance)
	{
		this->xPosition -= distance;
		this->odometer += distance;
	}
	void moveRight(int distance)
	{
		this->xPosition += distance;
		this->odometer += distance;
	}
	void display()
	{
		cout << this->name << "(" << this->odometer << ")\n"
			<< "x: " << this->xPosition << " y: " << this->yPosition << endl;
	}
};
#endif
