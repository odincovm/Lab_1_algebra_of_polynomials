#include <vector>
#include <String>
#include <Polynom.h>
using namespace std;
struct record {
	string name;
	Polinom pol;
};
class LinearArrayTable {
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
	Polinom find(string findname) {
		for (int i = 0;i < size;i++) {
			if (Table[i].name == findname) {
				return Table[i].Polinom;
			}
		}
		throw "Notfound";
	}
};