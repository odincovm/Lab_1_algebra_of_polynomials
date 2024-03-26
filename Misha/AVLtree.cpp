#include <String>
#include <iostream>
using namespace std;
class AVLTree {
	// Вспомогательные структуры
	struct record
	{
		string key;
		Polynom pol;
	};
	struct TNode
	{
		record data;
		unsigned char height;
		TNode* pLeft = nullptr;
		TNode* pRight = nullptr;
	};
	
	TNode* root;
	// Вспомогательные функции для дерева поиска
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
	// Вспомогательные функции для АВЛ дерева
	unsigned char getheight(TNode* p)
	{
		if (p == nullptr)
			return 0;
		else
			return p->height;
	}
	int bfactor(TNode* p)
	{
		return getheight(p->pRight) - getheight(p->pLeft);
	}
	void fixheight(TNode* p)
	{
		unsigned char hl = getheight(p->pLeft);
		unsigned char hr = getheight(p->pRight);
		p->height = (hl > hr ? hl : hr) + 1;
	}
		// Функции для баланисировки
	// правый поворот вокруг p
	TNode* rotateright(TNode* p) 
	{
		TNode* q = p->pLeft;
		p->pLeft = q->pRight;
		q->pRight = p;
		fixheight(p);
		fixheight(q);
		return q;
	}
	// левый поворот вокруг q
	TNode* rotateleft(TNode* q) 
	{
		TNode* p = q->pRight;
		q->pRight = p->pLeft;
		p->pLeft = q;
		fixheight(q);
		fixheight(p);
		return p;
	}
	TNode* balance(TNode* p) // балансировка узла p
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->pRight) < 0)
				p->pRight = rotateright(p->pRight);
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->pLeft) > 0)
				p->pLeft = rotateleft(p->pLeft);
			return rotateright(p);
		}
		return p; // балансировка не нужна
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
			root = balance(root);
		}
	}
	void deleterecord(string key) {
		TNode* delNote = FindNode(key, root);
		root = balance(root);
		delNote = nullptr;
	}

};