#pragma once
#include <string>
#include <map>
#include "../TABLES/AbstractTable.h"
#include "../TABLES/Polynom.h"

using namespace std;

class TPostfix
{
	//    string infix;
	//    string postfix;
	//public:
	//    TPostfix()
	//    {
	//        infix = "a + b";
	//    }
	//    TPostfix(string str) {
	//        infix = str;
	//    }
	//    bool isDigit(const char num) const;
	//    bool isLetter(const char a) const;
	//    bool isOperator(const char op) const;
	//    int precedence(const char op) const;
	//    string GetInfix() { return infix; }
	//    string GetPostfix() { return postfix; }
	//    string ToPostfix();
	//    double Calculate(); // ¬вод переменных, вычисление по постфиксной форме

	string infix;
	vector<string> postfix;
	static map<char, int> priority;
	vector<string> lexems;
	void Parse();
	void ToPostfix();
public:
	TPostfix(string infix);
	string GetInfix();
	vector<string> GetPostfix();

	double Calculate(AbstractTable* polynoms, double x, double y, double z);

	friend ostream& operator<<(ostream& o, TPostfix& p);
};