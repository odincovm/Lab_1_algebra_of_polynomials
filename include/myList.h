#pragma once

template <typename T>
class myList {
	struct Node {
		T data;
		Node* pNext;
	};
	Node<T>* pFirst;
	size_t size;
public:
	myList(): pFirst(nullptr), size(0){}
	myList(myList&& list) noexcept {
		pFirst = nullptr;
		swap(*this, list);
	}
	myList(const myList& list) {
		pFirst = nullptr;
		size = list.size;
		if (list.pFirst == nullptr) return;
		Node<T>* pNew = pNew = new Node<T>{ *list.pFirst };
		for (; pNew->pNext != nullptr; pNew = pNew->pNext) {
			pNew->pNext = new Node<T>{ *pNew->pNext };
		}
	}
	~myList() {
		Node<T>* p;
		while (pFirst != nullptr) {
			p = pFirst;
			pFirst = pFirst->pNext;
			delete p;
		}
	}
	size_t size() const noexcept{}
	bool isEmpty() const noexcept {}
	bool addNode(T node){}
	bool delNode(){}
	T& popFront(){}
	bool insertNode(const T& node, size_t pos){}
	T& getNode(size_t pos) {}
	myList operator=(const myList& list){}
	myList operator=(myList&& list){}
	Node<T>* ToPos(size_t pos) {}
	T& operator[](size_t pos) {}
	bool eraseAfter(size_t pos) {}
	
	void removeZeroCoefficient() {} // метод для удаления "нулевых" узлов полинома
};