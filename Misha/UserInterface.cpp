#include <stdio.h>
#include <LinearArrayTable.cpp>
#include <vector>
#include <iostream>
using namespace std;
class Userinteface
{
	int CodeActivTable;
	// Объявление таблиц
	LinearArrayTable LArrTable;



public:
	// Выбор актиыной таблицы
	void chooseactiveTable(){
		cout << "Выберите активную таблицу\n";
		cout << "1 - Линейная таблица на массиве\n";
		cout << "2 - АВЛ дерево \n";
		cout << "3 - Красно-черное дерево\n";
		cout << "5 - Хэш-таблица c открытым переименованием\n";
		cout << "6 - Упорядоченная таблица на массиве\n";
		cout << "7 - Хэш таблица с цепочками\n";
		cin >> CodeActivTable;
	}
	void add() {
		LArrTable.add()
	}
	// 
};