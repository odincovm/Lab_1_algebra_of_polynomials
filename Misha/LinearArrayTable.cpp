
#include <iostream>
#include <String>
#include <vector>
#include "../Project1/Polynom.h"
#include"../Project1/AbstractTable.h"
using namespace std;

class LinearArrayTable : public AbstractTable{
	struct record {
		string name;
		Polynom pol;
		record(string key, Polynom poly) { name = key; pol = poly; }
	};
	size_t size = 0;
	vector<record> Table;
public:
	size_t getsize() { return size; }
	void insert(std::string key, const Polynom& value) override {
		record newrecord{ key,value };
		// Проверка на, то что записи еще нет в таблице
		for (int i = 0; i < size; i++) {
			if (Table[i].name == newrecord.name)
				return;
		}
		// добавление новой записи
		Table.push_back(newrecord);
		size++;
	}
	void remove(const std::string key)override {
		deleteRecord(key);
	}
	Polynom& search(const std::string& key)override {
		for (int i = 0; i < size; i++) {
			if (Table[i].name == key) {
				return Table[i].pol;
			}
		}
		throw nullptr;
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
	Polynom* find(string findname) {
		for (int i = 0;i < size;i++) {
			if (Table[i].name == findname) {
				return &Table[i].pol;
			}
		}
		throw nullptr;
	}
	// Вывод таблицы на экран
	void printTable() override{
		cout << "Linear Array Table" << endl;
		for (int i = 0;i < size;i++) {
			record tmp = Table[i];
			cout << tmp.name << " | ";
			tmp.pol.printPolynom();	
			cout << "\n";
		}
	}
};