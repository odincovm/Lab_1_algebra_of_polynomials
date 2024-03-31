#include <iostream>
#include <string>
#include "ListTable.h"
#include "HashTable.h"
#include "../Postfix/ArrayTable.h";
#include "../Postfix/HashTable1.h"
#include "Postfix.h"
#include "../Misha/AVLtree.cpp"
#include "../Misha/LinearArrayTable.cpp"
#include "Polynom.h"
#include "menu.h"
#include <locale>

// xyz+4x7y5z3-9x5z pol1
// 1x2y3z4-5x6y7z8+9yz2 pol2

using namespace std;
enum ActiveTable {
	List_Table,
	Hash_Table,
	Hash_Table1,
	AVL_tree,
	Linear_table,
	Array_table
};

template<class T>
Polynom find(T& table, const string& pseudo) {
	Polynom searchPol;
	try {
		searchPol = table.search(pseudo);
		searchPol.printPolynom();
	}
	catch (exception) {
		cout << "Not Found" << endl;
	}
	return searchPol;
}

template <class T>
Polynom operation(Polynom& res, vector<string>& terms, T& table, char sign, int i) {
	Polynom first;
	Polynom second;
	if (terms[i][0] == sign)
		terms[i] = terms[i].substr(1);

	if (terms[i + 1][0] == sign)
		terms[i + 1] = terms[i + 1].substr(1);
	if (i != 0)
		first = res;
	else
		first = find(table, terms[i]);
	second = find(table, terms[i + 1]);

	if (sign == '-') {
		first.substractPolynom(second);
		return first;
	}
	if (sign == '+') {
		first.addPolynom(second);
		return first;
	}
	if (sign == '*') {
		first.multiplyPolynom(second);
		return first;
	}
}

void main(void) {
	setlocale(LC_ALL, "rus");

	LinkedListTable listTable;
	HashTable<Polynom> hashTable;
	HashTable1 hashTable1;
	ArrayTable arrTable;
	LinearArrayTable linArrTable;
	AVLTree avlTree;

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
	int activeTable = 0;
	string str;
	while (selector != KEY_EXIT) {
		system("cls");
		selector = menu(menu1, 7);
		switch (selector) {
		case 0: {
			system("cls");
			char* menu2[6] = {
			(char*)"List Table",
			(char*)"Hash Table with open adress",
			(char*)"Hash Table with lists",
			(char*)"AVL tree",
			(char*)"Linear Table",
			(char*)"Array Table"
			};
			activeTable = menu(menu2, 6);
			switch (activeTable)
			{
			case 0: {
				system("cls");
				cout << "Выбрана List таблица" << endl;
				system("pause");
				break;
			}
			case 1: {
				system("cls");
				cout << "Выбрана хеш таблица с открытым перемешиванием" << endl;
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				cout << "Выбрана хеш таблица с методом цепочек" << endl;
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				cout << "Выбрано АВЛ дерево" << endl;
				system("pause");
				break;
			}
			case 4: {
				system("cls");
				cout << "Выбрана линейная таблица" << endl;
				system("pause");
				break;
			}
			case 5: {
				system("cls");
				cout << "Выбрана таблица на массиве" << endl;
				system("pause");
				break;
			}
			}
			break;
		}
		case 1: {
			system("cls");
			string pol, key;
			Polynom temp;
			cout << "Enter the poly: ";
			cin >> pol;
			temp.parseAndAddMonoms(pol);
			cout << "Enter the pseudo: ";
			cin >> key;
			listTable.insert(key, temp);
			hashTable.insert(key, temp);
			hashTable1.insert(key, temp);
			avlTree.add(key, temp);
			linArrTable.add(key, temp);
			arrTable.insert(key, temp);
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			string key;
			cout << "Enter the pseudo to delete the poly: ";
			cin >> key;
			try {
				listTable.remove(key);
				hashTable.remove(key);
				arrTable.remove(key);
				linArrTable.deleteRecord(key);
				avlTree.deleterecord(key);
				hashTable1.remove(key);
			}
			catch (exception) {
				cout << "Key is not found!" << endl;
			}
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			Polynom search;
			string key;
			cout << "Enter the key to find the poly: ";
			cin >> key;
			switch (activeTable) {
			case List_Table: {
				search = find(listTable, key);
				break;
			}
			case Hash_Table: {
				search = find(hashTable, key);
				break;
			}
			case Hash_Table1: {
				search = find(hashTable1, key);
				break;
			}
			case AVL_tree: {
				search = *avlTree.Find(key);
				search.printPolynom();
				break;
			}
			case Linear_table: {
				search = *linArrTable.find(key);
				search.printPolynom();
				break;
			}
			case Array_table: {
				search = find(arrTable, key);
				break;
			}
			}
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			switch (activeTable) {
			case List_Table: {
				listTable.printTable();
				break;
			}
			case Hash_Table: {
				hashTable.printTable();
				break;
			}
			case Hash_Table1: {
				hashTable1.printTable();
				break;
			}
			case AVL_tree: {
				avlTree.Print();
				break;
			}
			case Linear_table: {
				linArrTable.printTable();
				break;
			}
			case Array_table: {
				arrTable.printTable();
				break;
			}
			}
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			Polynom search;
			string key;
			double x, y, z;
			cout << "Enter the pseudo to calc the poly: ";
			cin >> key;
			switch (activeTable) {
			case List_Table: {
				search = find(listTable, key);
				break;
			}
			case Hash_Table: {
				search = find(hashTable, key);
				break;
			}
			case Hash_Table1: {
				search = find(hashTable1, key);
				break;
			}
			case AVL_tree: {
				search = *avlTree.Find(key);
				search.printPolynom();
				break;
			}
			case Linear_table: {
				search = *linArrTable.find(key);
				search.printPolynom();
				break;
			}
			case Array_table: {
				search = find(arrTable, key);
				break;
			}
			system("pause");
			break;
			}
			cout << "Enter the x: "; cin >> x;
			cout << "Enter the y: "; cin >> y;
			cout << "Enter the z: "; cin >> z;
			double res = search.calcPolynom(x, y, z);
			cout << res << endl;
			system("pause");
			break;
		}
		case 6: {
			system("cls");

			string expr;
			Polynom first;
			Polynom second;
			Polynom resPoly;
			double x, y, z, res;

			cout << "Enter the expression: ";
			cin >> expr;

			//vector<string> terms;
			//size_t pos = 0;
			//size_t nextSignPos = 0;
			//do
			//{
			//	nextSignPos = expr.find_first_of("+-*", pos + 1);
			//	if (nextSignPos == string::npos)
			//	{
			//		nextSignPos = expr.size();
			//	}
			//	string term = expr.substr(pos, nextSignPos - pos);
			//	pos = nextSignPos;
			//	terms.push_back(term);
			//} while (nextSignPos < expr.size());
			//terms.push_back(" ");

			//for (int i = 0; i < terms.size() - 1; i++) {
			//	if (terms[i + 1] != " ") {
			//		// Вычитание
			//		if (terms[i][0] == '-' && terms[i + 1][0] != '-' ||
			//			terms[i][0] != '-' && terms[i + 1][0] == '-' ||
			//			terms[i][0] == '-' && terms[i + 1][0] == '-')
			//		{
			//			first = operation(resPoly, terms, listTable, '-', i);
			//		}

			//		// Сложение

			//		if (terms[i][0] == '+' && terms[i + 1][0] != '+' ||
			//			terms[i][0] != '+' && terms[i + 1][0] == '+' ||
			//			terms[i][0] == '+' && terms[i + 1][0] == '+')
			//		{
			//			first = operation(resPoly, terms, listTable, '+', i);
			//		}

			//		// Умножение

			//		if (terms[i + 1][0] == '*') {
			//			first = operation(resPoly, terms, listTable, '*', i);
			//		}

			//		resPoly = first;
			//	}
			//}

			cout << "Enter the x: ";
			cin >> x;
			cout << "Enter the y: ";
			cin >> y;
			cout << "Enter the z: ";
			cin >> z;
			AbstractTable* table = nullptr;
			TPostfix calc(expr);
			switch (activeTable) {
			case List_Table: {
				table = &listTable;
				break;
			}
			case Hash_Table: {
				table = &hashTable;
				break;
			}
			case Hash_Table1: {
				table = &hashTable1;
				break;
			}
			case AVL_tree: {
				//
				break;
			}
			case Linear_table: {
				//
				break;
			}
			case Array_table: {
				table = &arrTable;
				break;
			}
			}
			res = calc.Calculate(table, x, y, z);
			cout << res << endl;
			//resPoly.printPolynom();
			system("pause");
			break;
		}
		}
	}
}