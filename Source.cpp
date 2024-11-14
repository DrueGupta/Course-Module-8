#include <iostream>
#include <string>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
using namespace std;

int main()
{
	TaxiCompany PickmeUp;
	PickmeUp.addTaxi("Big Slappy", 10.00);
	PickmeUp.addTaxi("Ambatakam", 5.00);
	PickmeUp.addTaxi("King", 200.00);
	PickmeUp.orderTaxi(5, 8, 12, 9);
	PickmeUp.orderTaxi(- 2, - 8, 2, 2);
}
