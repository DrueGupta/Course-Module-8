#include <iostream>
#include <string>
#include <Vector>
#include <cmath>
#include "Header1.h"
using namespace std;

class TaxiCompany
{
private:
	string name;
	vector<Taxiservice> taxis;
	double account;
public:
	TaxiCompany(string name)
	{
		this->name = name;
		this->account = 0;
	}
	TaxiCompany() : TaxiCompany("")
	{
	//RAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH
	}
	string getName()
	{
		this->name = name;
	}
	double getAccount()
	{
		return this->account;
	}
	void addTaxi(string name, double rate)
	{
		Taxiservice newTaxi(name, rate);
		this->taxis.push_back(newTaxi);
	}
	double distance(int aX, int aY, int bX, int bY) 
	{
		return abs(bX - aX) + abs(bY - aY);
	}
	void orderTaxi(int beginX, int beginY, int endX, int endY)
	{
		int closestIndex = 0, farAway = 0, minFarAway = 0;
		minFarAway = this->distance( taxis[0].getX(), taxis[0].getY(), beginX, beginY);
		for (int i = 0; i < taxis.size(); i++)
		{
			farAway = this->distance(taxis[i].getX(), taxis[i].getY(), beginX, beginY);
			if (farAway < minFarAway)
			{
				closestIndex = i;
				minFarAway = farAway;
			}
		}
		this->taxis[closestIndex].callTaxi(beginX, beginY, endX, endY);
	}
	void collect()
	{
		for (Taxiservice& taxi : this->taxis) {
			this->account += taxi.account;
			taxi.account = 0;
		}
	}
	void display()
	{
		cout << this->name << endl
			<< this->account << endl;
		for (Taxiservice& taxi : this->taxis)
		{
			cout << "---------------\n";
			taxi.display();
		}
	}
};
