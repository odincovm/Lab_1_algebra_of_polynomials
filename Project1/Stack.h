#pragma once
const int MaxStackSize = 100;

template <typename T>
class MyStack {
    T* pMem;
    size_t size;
    int top;
public:
    MyStack()
    {
        size = 1;
        top = -1;
        pMem = new T[size];
    }

    MyStack(const MyStack& s)
    {
        size = s.size;
        top = s.top;
        pMem = new T[s.size];
        copy(s.pMem, s.pMem + top + 1, pMem);
    }

    MyStack& operator=(const MyStack& s) {
        if (this != &s) {
            T* tmp = new T[s.size];
            size = s.size;
            top = s.top;
            delete[] pMem;
            pMem = tmp;
            for (size_t i = 0; i < size; i++)
            {
                pMem[i] = s.pMem[i];
            }
        }
        return *this;
    }

    ~MyStack() {
        delete[] pMem;
    }

    T Pop() {
        if (top < 0) {
            throw "Stack is empty";
        }
        return pMem[top--];
    }

    void Push(T val) {
        if (top + 1 == MaxStackSize)
            throw "Maximum number of items reached";
        if (top == size - 1)
        {
            T* tmp = new T[size + size];
            for (int i = 0; i < size; ++i) {
                tmp[i] = pMem[i];
            }
            delete[] pMem;
            pMem = tmp;
            size += size;
        }
        pMem[++top] = val;
    }

    size_t GetSize() {
        return top + 1;
    }

    bool IsEmpty() {
        return top == -1;
    }
};