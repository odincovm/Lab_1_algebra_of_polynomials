#pragma once
#include "..\tables\AbstractTable.h"
#define START_CAPACITY 2

class ArrayTable : public AbstractTable {
    typedef struct KeyValuePair {
        string key;
        Polynom value;
    } KeyValuePair;

    KeyValuePair* arr;
    int count = 0;
    int capacity;

    int find_index(string key);

public:
    ArrayTable();
    ~ArrayTable();
    //virtual void sortTable();
    virtual void insert(std::string key, const Polynom& value); //  виртуальная функция для вставки
    virtual Polynom& search(std::string key); //  виртуальная функция для поиска
    virtual void remove(std::string key); //  виртуальная функция для удаления
    virtual void printTable();
};