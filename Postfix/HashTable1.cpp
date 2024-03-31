#include "HashTable1.h"
#include "../Project1/AbstractTable.h"

HashTable1::HashTable1() {
	count = 0;
}

HashTable1::~HashTable1() {
	Node<HashTable1::Bucket*>* x;
	while (!buckets.IsEmpty()) {
		x = buckets.FrontNode();
		while (!x->data->chain.IsEmpty()) {
			x->data->chain.popFront();
		}
		buckets.popFront();
	}
}

Node<HashTable1::Bucket*>* HashTable1::findInList(unsigned long long h) {
	Node<Bucket*>* x = buckets.FrontNode();
	while (x != NULL) {
		if (x->data->key == h) {
			break;
		}
		x = x->pNext;
	}
	return x;
}

void HashTable1::insert(std::string key, const Polynom& value) {
	HashTable1::KeyValuePair kvp;
	kvp.key = key;
	kvp.value = value;
	unsigned long long h = GetHash(key);
	Node<Bucket*>* x = findInList(h);
	if (x == NULL) {
		Bucket* b = new Bucket();
		b->key = h;
		b->chain.addNode(kvp);
		buckets.addNode(b);
	}
	else {
		x->data->chain.addNode(kvp);
	}
}

Polynom& HashTable1::search(const std::string& key) {
	unsigned long long h = GetHash(key);
	Node<Bucket*>* x = findInList(h);
	if (x != NULL) {
		Node<KeyValuePair>* y = x->data->chain.FrontNode();
		while (y != NULL) {
			if (y->data.key == key) {
				return y->data.value;
			}
			y = y->pNext;
		}
		throw exception("Key not found in HashTable");
	}
	throw exception("Key/Hash not found in HashTable");
}
void HashTable1::remove(std::string key) {
	unsigned long long h = GetHash(key);
	int m;
	Node<Bucket*>* x = findInList(h);
	if (x != NULL) {
		Node<KeyValuePair>* y = x->data->chain.FrontNode();
		m = 0;
		while (y != NULL) {
			if (y->data.key == key) {
				break;
			}
			++m;
			y = y->pNext;
		}
		if (y == NULL) throw "Key not found in HashTable";
		--m;
		if (m >= 0) {
			x->data->chain.eraseAfter(m);
		}
		else {
			x->data->chain.popFront();
		}
		if (x->data->chain.IsEmpty()) {
			x = buckets.FrontNode();
			m = 0;
			while (x != NULL) {
				if (x->data->key == h) {
					break;
				}
				++m;
				x = x->pNext;
			}
			--m;
			if (m >= 0) {
				buckets.eraseAfter(m);
			}
			else {
				buckets.popFront();
			}
		}
	}
	//throw "Key/Hash not found in HashTable";
}
void HashTable1::printTable() {
	Node<Bucket*>* x = buckets.FrontNode();
	Node<KeyValuePair>* y;
	cout << "Hash table output" << endl;
	cout << "Hash function value\tName\tPolynom" << endl;
	int m;
	while (x != NULL) {
		cout << x->data->key << "\t: ";
		y = x->data->chain.FrontNode();
		m = 0;
		while (y != NULL) {
			if (m > 0) cout << ", ";
			cout << y->data.key << "\t: ";
			y->data.value.printPolynom();
			y = y->pNext;
			++m;
		}
		x = x->pNext;
	}
}

unsigned long long HashTable1::GetHash(string key) {
	int r = 2;
	int dr = 17;
	unsigned long long h = 0;
	unsigned long long c;
	for (int i = 0; i < key.length(); ++i) {
		c = key[i];
		h ^= ((c >> r) | (c << (64 - r)));
		r = (r + dr) & 0x3F;
	}
	return h;
}