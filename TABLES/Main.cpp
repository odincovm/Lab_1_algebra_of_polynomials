#include <iostream>
#include <string>
#include "ListTable.h"
#include "Polynom.h"
#include "menu.h"
#include <locale>

using namespace std;

//void main(void) {
//	Polynom poly;
//	poly.parseAndAddMonoms("xyz+2x3y4z-7x5z6");
//	Polynom poly1;
//	poly1.parseAndAddMonoms("x3y4z+5x5y2z6");
//	LinkedListTable listTable;
//	listTable.insert("pol1", poly);
//	listTable.insert("pol100", poly1);
//	listTable.printTable();
//	cout << "*************" << endl;
//	Polynom srch;
//	try {
//		srch = listTable.search("pol100");
//	}
//	catch (exception){
//		cout << "Not Found";
//	}
//	srch.printPolynom();
//	Polynom op;
//	op = listTable.search("pol1");
//	op.addPolynom(srch);
//	cout << "******************" << endl;
//	op.printPolynom();
//}

void main() {
	setlocale(LC_ALL, "rus");
	char* menu1[7] = {
		(char*)"Изменить активную таблицу",
		(char*)"Добавить полином в таблицы",
		(char*)"Удалить полином из таблиц",
		(char*)"Найти полином по имени",
		(char*)"Вывести все полиномы",
		(char*)"Вычислить полином в заданной точке",
		(char*)"Вычислить выражение из полиномов"
	};
	int selector = 0;
	string str;
	while (selector != KEY_EXIT) {
		system("cls");
		selector = menu(menu1, 7);
		switch (selector) {
		case 0: {
			system("cls");
			system("pause");
			break;
		}
		case 1: {
			system("cls");
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			system("pause");
			break;
		}
		case 6: {
			system("cls");
			system("pause");
			break;
		}
		}
	}
}
