#pragma once
#include "AbstractTable.h"
#include <iostream>
#include <vector>
#include "Polynom.h"

class LinkedListTable : public AbstractTable {
private:
	struct Node {
		string key;
		Polynom value;
		Node* next;
	};

	Node* head;
	size_t size;
public:
	LinkedListTable() {
		size = 0;
		head = nullptr;
	}
	~LinkedListTable() {}
	//void sortTable() {}
	void insert(string key, const Polynom& value) override {

		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		if (size == 0) {
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
		size++;
	}

	Polynom& search(const string& key) override {
		Node* tmp = head;
		while (tmp != nullptr) {
			if (tmp->key == key)
				return tmp->value;
			tmp = tmp->next;
		}
		throw exception("NotFound");
	}

	Node* ToPos(string key) {
		if (size == 0) return nullptr;
		Node* prev = nullptr;
		Node* current = head;

		for (size_t i = 0; i < size; i++) {
			if (current->key == key) {
				prev = current;
				return prev;
			}
			current = current->next;
			prev = current;
		}
		return nullptr;
	}

	void remove(const string key) override {
		if (size == 0) {
			throw exception("ListTable is empty");
		}

		if (head->key == key) {
			Node* temp = head;
			head = head->next;
			delete temp;
			size--;
			return;
		}

		Node* prev = nullptr;
		Node* current = head;

		while (current != nullptr && current->key != key) {
			prev = current;
			current = current->next;
		}

		if (current == nullptr) {
			throw exception("Key not found in the list");
		}

		if (current->key == key) {
			prev->next = current->next;
			delete current;
			size--;
		}
	}

	void printTable() override {
		Node* current = head;
		cout << "LIST TABLE" << endl;
		cout << "KEY                 |           POLYNOM  " << endl;
		while (current != nullptr) {
			cout << "___________________________________________________" << endl;
			cout << current->key;
			for (int i = 0; i < 20 - current->key.size(); i++)
				cout << " ";
			cout << "|       ";
			current->value.printPolynom();
			current = current->next;
		}
	}
};