#pragma once
#include "..\tables\AbstractTable.h"
#include "..\TABLES\myList.h"

using namespace std;

static const int default_size = 8; // начальный размер нашей таблицы
constexpr static const double rehash_size = 0.75; // коэффициент, при котором произойдет увеличение таблицы

int HashFunction(const string& s, int table_size, const int key)
{
	int hash_result = 0;
	for (int i = 0; i < s.size(); ++i)
		hash_result = (key * hash_result + s[i]) % table_size;
	hash_result = (hash_result * 2 + 1) % table_size;
	return hash_result;
}
struct HashFunction1
{
	int operator()(const string& s, int table_size) const
	{
		return HashFunction(s, table_size, table_size - 1); // ключи должны быть взаимопросты, используем числа <размер таблицы> плюс и минус один.
	}
};
struct HashFunction2
{
	int operator()(const string& s, int table_size) const
	{
		return HashFunction(s, table_size, table_size + 1);
	}
};

template <class THash1 = HashFunction1, class THash2 = HashFunction2>
class HashTable : public AbstractTable {
	struct Node
	{
		string key;
		Polynom value;
		bool state; // если значение флага state = false, значит элемент массива был удален (deleted)

		Node(const Polynom& value_, string _key) {
			value = value_;
			key = _key;
			state = true;
		}
	};
	Node** arr; // соответственно в массиве будут хранится структуры Node*
	int size; // сколько элементов у нас сейчас в массиве (без учета deleted)
	int buffer_size; // размер самого массива, сколько памяти выделено под хранение нашей таблицы
	int size_all_non_nullptr; // сколько элементов у нас сейчас в массиве (с учетом deleted)

	void Resize() {
		int past_buffer_size = buffer_size;
		buffer_size *= 2;
		size_all_non_nullptr = 0;
		size = 0;
		Node** arr2 = new Node * [buffer_size]();
		for (int i = 0; i < buffer_size; ++i)
			arr2[i] = nullptr;
		swap(arr, arr2);
		for (int i = 0; i < past_buffer_size; ++i) {
			if (arr2[i] && arr2[i]->state)
				insert(arr2[i]->key, arr2[i]->value);
		}
		for (int i = 0; i < past_buffer_size; ++i)
			delete arr2[i];
		delete[] arr2;
	}

	void Rehash() {
		size_all_non_nullptr = 0;
		size = 0;
		Node** arr2 = new Node * [buffer_size]();
		for (int i = 0; i < buffer_size; ++i)
			arr2[i] = nullptr;
		swap(arr, arr2);
		for (int i = 0; i < buffer_size; ++i) {
			if (arr2[i] && arr2[i]->state)
				insert(arr2[i]->key, arr2[i]->value);
		}
		for (int i = 0; i < buffer_size; ++i)
			delete arr2[i];
		delete[] arr2;
	}

public:
	HashTable()
	{
		buffer_size = default_size;
		size = 0;
		size_all_non_nullptr = 0;
		arr = new Node * [buffer_size];
		for (int i = 0; i < buffer_size; i++)
			arr[i] = nullptr;
	}
	~HashTable()
	{
		for (int i = 0; i < buffer_size; ++i)
			if (arr[i])
				delete arr[i];
		delete[] arr;
	}
	void insert(string key, const Polynom& value) override
	{
		if (size + 1 > int(rehash_size * buffer_size))
			Resize();
		else if (size_all_non_nullptr > 2 * size)
			Rehash(); // происходит рехеш, так как слишком много deleted-элементов
		int h1 = HashFunction1()(key, buffer_size);
		int h2 = HashFunction2()(key, buffer_size);
		int i = 0;
		int first_deleted = -1; // запоминаем первый подходящий (удаленный) элемент
		while (arr[h1] != nullptr && i < buffer_size)
		{
			if (arr[h1]->key == key && arr[h1]->state)
				return; // такой элемент уже есть, а значит его нельзя вставлять повторно
			if (!arr[h1]->state && first_deleted == -1) // находим место для нового элемента
				first_deleted = h1;
			h1 = (h1 + h2) % buffer_size;
			++i;
		}
		if (first_deleted == -1) // если не нашлось подходящего места, создаем новый Node
		{
			Node* buf = new Node(value, key);
			arr[h1] = buf;
			++size_all_non_nullptr; // так как мы заполнили один пробел, не забываем записать, что это место теперь занято
		}
		else
		{
			arr[first_deleted]->value = value;
			arr[first_deleted]->key = key;
			arr[first_deleted]->state = true;
		}
		++size; // и в любом случае мы увеличили количество элементов
		return;
	}
	Polynom& search(const string& key) override
	{
		int h1 = HashFunction1()(key, buffer_size); // значение, отвечающее за начальную позицию
		int h2 = HashFunction2()(key, buffer_size); // значение, ответственное за "шаг" по таблице
		int i = 0;
		while (arr[h1] != nullptr && i < buffer_size)
		{
			if (arr[h1]->key == key && arr[h1]->state)
				return arr[h1]->value; // такой элемент есть
			h1 = (h1 + h2) % buffer_size;
			++i; // если у нас i >=  buffer_size, значит мы уже обошли абсолютно все ячейки, именно для этого мы считаем i, иначе мы могли бы зациклиться.
		}
		throw exception("Not Found");
	}
	void remove(const string key) override
	{
		int h1 = HashFunction1()(key, buffer_size);
		int h2 = HashFunction2()(key, buffer_size);
		int i = 0;
		while (arr[h1] != nullptr && i < buffer_size)
		{
			if (arr[h1]->key == key && arr[h1]->state)
			{
				arr[h1]->state = false;
				--size;
				return;
			}
			h1 = (h1 + h2) % buffer_size;
			++i;
		}
	}
	void printTable() override {
		cout << "HASH TABLE" << endl;
		cout << "KEY                 |           POLYNOM  " << endl;
		for (int i = 0; i < buffer_size; ++i) {
			if (arr[i] != nullptr && arr[i]->state) {
				cout << "___________________________________________________" << endl;
				cout << arr[i]->key;
				for (int j = 0; j < 20 - arr[i]->key.size(); j++)
					cout << " ";
				cout << "|       ";
				arr[i]->value.printPolynom();
			}
		}
	}
};
