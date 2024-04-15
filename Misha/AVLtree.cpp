#include <String>
#include <iostream>
#include "../Project1/Polynom.h"
#include "../Project1/AbstractTable.h"
using namespace std;
class AVLTree :public AbstractTable{
	// Вспомогательные структуры
	struct record
	{
		string key;
		Polynom pol;
		record(string _key, Polynom poly) { key = _key; pol = poly; }
		record() { ; }
	};
	struct TNode
	{
		record data;
		unsigned char height;
		TNode* pLeft = 0;
		TNode* pRight = 0;
		TNode(record dat) {data=dat; pLeft = pRight = 0; height = 1; }
	};
	size_t size = 0;
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
			if (pNode == nullptr)
				return nullptr;
		}
		if (key > pNode->data.key) {
			pNode = FindNode(key, pNode->pRight);
			if (pNode == nullptr)
				return nullptr;
		}
		return pNode;
	}
	TNode* insert(record newrecord, TNode* pNode) {
		TNode* newNode = new TNode(newrecord);
		if (pNode == nullptr) {
			root = newNode;
			return balance(pNode);
		}
		if (newrecord.key < pNode->data.key) {
			if (pNode->pLeft == nullptr) {
				pNode->pLeft = newNode;
				return balance(pNode);
			}
			insert(newrecord, pNode->pLeft);
		}
		if (newrecord.key > pNode->data.key) {
			if (pNode->pRight == nullptr) {
				pNode->pRight = newNode;
				return balance(pNode);
			}
			insert(newrecord, pNode->pRight);
		}
		return pNode;
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
		if (p == nullptr)
			return 0;

		return getheight(p->pRight) - getheight(p->pLeft);
	}
	void fixheight(TNode* p)
	{
		if (p == nullptr)
			return;
		fixheight(p->pLeft);
		fixheight(p->pRight);
		unsigned char hl = getheight(p->pLeft);
		unsigned char hr = getheight(p->pRight);
		p->height = (hl > hr ? hl : hr) + 1;

	}
		// Функции для баланисировки
	// правый поворот вокруг p
	TNode* rotateright(TNode* p) 
	{
		TNode* tmp1 = p;
		p = p->pLeft;
		TNode* tmp2 = p->pRight;
		p->pRight = tmp1;
		p->pRight->pLeft = tmp2;
		return p;
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
	// Для удаления
	TNode* findmin(TNode* p) // поиск узла с минимальным ключом в дереве p 
	{
		if (p->pLeft)
			findmin(p->pLeft);
		return p;
	}
	TNode* removemin(TNode* p) // удаление узла с минимальным ключом из дерева p
	{
		if (p->pLeft == 0)
			return p->pRight;
		p->pLeft = removemin(p->pLeft);
		return balance(p);
	}
	TNode* remove(TNode* p, string k) // удаление ключа k из дерева p
	{
		if (!p) return 0;
		if (k < p->data.key)
			p->pLeft = remove(p->pLeft, k);
		else if (k > p->data.key)
			p->pRight = remove(p->pRight, k);
		else //  k == p->key 
		{
			TNode* q = p->pLeft;
			TNode* r = p->pRight;
			delete p;
			if (!r) return q;
			TNode* min = findmin(r);
			min->pRight = removemin(r);
			min->pLeft = q;
			return balance(min);
		}
		return balance(p);
	}
public:
	size_t getsize() { return size; }
	void printTable()override {
		cout << "Table\n";
		Print(root);
	}
	Polynom& search(const std::string& key) {
		TNode* pNode = FindNode(key, root);
		if (pNode == nullptr)
			throw nullptr;
		return pNode->data.pol;
	}
	Polynom* oldserch(string key) {
		TNode* pNode = FindNode(key, root);
		if (pNode == nullptr)
			return nullptr;
		return &pNode->data.pol;
	}
	void insert(string key,const Polynom& newpol) override {
		record newrecord(key, newpol);
		// Проверка на наличие значения
		if (oldserch(newrecord.key) == nullptr) {
			// Поиск места, куда можно вставить элемент и его вставка
			insert(newrecord, root);
			root = balance(root);
			size++;
		}
	}
	void remove(const string key)override {
		if (oldserch(key) != nullptr) {
			remove(root, key);
			size--;
		}
	}

};