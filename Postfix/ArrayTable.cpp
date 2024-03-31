#include <string>
#include "ArrayTable.h"
#include "../Project1/Polynom.h"
using namespace std;

ArrayTable::ArrayTable() {
	arr = new KeyValuePair[START_CAPACITY];
	capacity = START_CAPACITY;
}

ArrayTable::~ArrayTable() {
	delete[] arr;
}

int ArrayTable::find_index(string key) {
	for (int i = 0; i < count; ++i) {
		if (arr[i].key == key) {
			return i;
		}
	}
	return -1;
}

void ArrayTable::insert(string key, const Polynom& value) {
	int t = find_index(key);
	if (t >= 0) {
		arr[t].value = value;
		return;
	}
	if (count == capacity) {
		capacity += capacity;
		KeyValuePair* tmp = new KeyValuePair[capacity];
		t = 0;
		while ((arr[t].key <= key) && (t < count)) {
			tmp[t] = arr[t];
			++t;
		}
		tmp[t].key = key;
		tmp[t].value = value;
		++t;
		while (t < count) {
			tmp[t] = arr[t - 1];
			++t;
		}
		delete arr;
		arr = tmp;
		++count;
		return;
	}
	t = count;
	/*while ((t > 0) && (arr[t - 1].key > key) && (t<capacity-1)) {
		arr[t] = arr[t - 1];
		t++;
	}*/
	arr[t].key = key;
	arr[t].value = value;
	count++;
}

Polynom& ArrayTable::search(const string& key) {
	int t = find_index(key);
	if (t >= 0) {
		return arr[t].value;
	}
	else
		throw exception("Key not found: ");
}

void ArrayTable::remove(string key) {
	bool found = false;
	for (int i = 0; i < count; i++) {
		if (arr[i].key == key) {
			found = true;
			for (int j = i; j < count - 1; j++) {
				arr[j] = arr[j + 1];
			}
			count--; 
			break; 
		}
	}

}

void ArrayTable::printTable() {
	cout << "Array table output" << endl << "Name\tPolynom" << endl;
	for (int i = 0; i < count; i++) {
		cout << arr[i].key << "\t";
		arr[i].value.printPolynom();
	}
}