#pragma once

template <typename T>
class myStack {
	size_t size;
	int top;
	T* pMem;
public:
	myStack() :top(-1), size(MaxStackSize) {
		pMem = new T[size]();
	};
	myStack(int _size)
	{
		if ((_size < 1) || (_size > MaxStackSize))
			throw _size;
		size = _size;
		top = -1;
		pMem = new T[size]();
	}
	myStack(const myStack& stck){}
	~myStack(){}
	void push(const T& data){}
	bool isEmpty() {}
	size_t size() const {}
	bool IsFull() const {}
	void push(const T& val) {}
	T Top() { return pMem[top]; }
	T pop() { return pMem[top--]; }
};