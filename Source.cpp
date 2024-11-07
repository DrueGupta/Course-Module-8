#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main()
{
	Taxicab a("Sam", 0, 0);
	a.moveRight(13);
	a.moveLeft(8);
	a.moveUp(6);
	a.moveDown(0);
}
