#include <String>

#include <iostream>
#include "../TABLES/Polynom.h"
using namespace std;
class SerrchTree {
	struct record
	{
		string key;
		Polynom pol;
	};
	struct TNode
	{
		record data;
		TNode* pLeft = nullptr;
		TNode* pRight = nullptr;
	};

	TNode* root;
	void Print(TNode* p) {
		if (p == nullptr)
			return;
		Print(p->pLeft);
		cout << p->data.key << " - ";
		p->data.pol.printPolynom();
		cout << endl;
		Print(p->pRight);
	}
	TNode* FindNode(string key, TNode* pNode) {
		if (pNode == nullptr)
			return nullptr;
		if (key < pNode->data.key) {
			pNode = FindNode(key, pNode->pLeft);
		}
		if (key < pNode->data.key) {
			pNode = FindNode(key, pNode->pRight);
		}
		return pNode;
	}
	TNode* add(record newrecord, TNode* pNode) {
		TNode* newNode;
		newNode->data = newrecord;
		if (newrecord.key < pNode->data.key) {
			if (pNode->pLeft == nullptr) {
				pNode->pLeft = newNode;
				return;
			}
			add(newrecord, pNode->pLeft);
		}
		if (newrecord.key > pNode->data.key) {
			if (pNode->pRight == nullptr) {
				pNode->pRight = newNode;
				return;
			}
			add(newrecord, pNode->pRight);
		}
		return;
	}
public:
	void Print() {
		cout << "Table\n";
		Print(root);
	}
	Polynom* Find(string key) {
		TNode* pNode = FindNode(key, root);
		if (pNode == nullptr)
			return nullptr;
		return &pNode->data.pol;
	}
	void add(record newrecord) {
		// Проверка на наличие значения
		if (Find(newrecord.key) == nullptr) {
			// Поиск места, куда можно вставить элемент и его вставка
			add(newrecord, root);
		}
	}
	void deleterecord(string key) {
		TNode* delNote = FindNode(key, root);
		delNote = nullptr;
	}
	
};