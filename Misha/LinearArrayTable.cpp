#include <iostream>
#include <String>
#include <vector>
#include "../include/Polynom.h"
using namespace std;

class LinearArrayTable {
	struct record {
		string name;
		Polynom pol;
	};
	size_t size = 0;
	vector<record> Table;
public:
	void add(record newrecord) {
		// Проверка на, то что записи еще нет в таблице
		for (int i = 0;i < size;i++) {
			if (Table[i].name == newrecord.name)
				return;
		}
		// добавление новой записи
		Table.push_back(newrecord);
		size++;
	}
	void deleteRecord (string deletename) {
		vector<record> newTable;
		for (int i = 0;i < size;i++) {
			// Перепаковка
			if (Table[i].name != deletename) {
				newTable.push_back(Table[i]);
			}
			//Удаление
			else {
				size -= 1;
				break;
			}
		}
		Table = newTable;
	}
	// Нахождение по ключу
	Polynom find(string findname) {
		for (int i = 0;i < size;i++) {
			if (Table[i].name == findname) {
				return Table[i].Polynom;
			}
		}
		throw "Notfound";
	}
	// Вывод таблицы на экран
	void printTable() {
		for (int i = 0;i < size;i++) {
			cout << record.name;
			record.pol.printPolynom();
			cout << "\n";
		}
	}
};