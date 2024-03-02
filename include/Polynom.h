#pragma once
#include "Monom.h"
#include "myList.h"

class Polynom {
	myList<Monom> poly;
public:
	Polynom() {}
	Polynom(const Polynom& pol) {}
	void parseAndAddMonoms(const string input);
	void printPolynom();
	void castMonom();
	void addPolynom(Polynom& p);
	void multiplyPolynom(Polynom& p);
	double calcPolynom(double x, double y, double z);
};