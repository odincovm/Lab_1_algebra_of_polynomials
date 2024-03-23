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
	LinkedListTable(){
		size = 0;
		head = nullptr;
	}
	~LinkedListTable() {}
	void sortTable() {}
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

	Polynom& search(string key) override {
		Node* tmp = head;
		while (tmp != nullptr) {
			if (tmp->key == key) 
				return tmp->value;
			tmp = tmp->next;
		}
		throw exception("NotFound");
	}

	Node* ToPos(string key) {
		Node* current = head;
		for (size_t i = 0; i < size; ++i) {
			if (current->next->key == key) return current;
			current = current->next;
		}
	}

	void remove(std::string key) override {
		if (size == 0) throw "list is empty";
		Node* p = ToPos(key);
		Node* pDel = p->next;
		p->next = pDel->next;
		delete pDel; 
		size--;
	}

	void printTable() override {
		Node* current = head;
		cout << "KEY                 |           POLYNOM  " << endl;
		while (current != nullptr) {
			cout << "___________________________________________________" << endl;
			cout << current->key; 
			for(int i=0; i < 20 - current->key.size(); i++)
				cout << " "; 
			cout << "|       ";
			current->value.printPolynom();
			current = current->next;
		}
	}
};