#pragma once
#include "../Project1/AbstractTable.h"
#define START_CAPACITY 10

class ArrayTable: public AbstractTable
{
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
    void insert(std::string key, const Polynom& value) override; //  виртуальная функция для вставки
    Polynom& search(const std::string& key) override; //  виртуальная функция для поиска
    void remove(std::string key) override; //  виртуальная функция для удаления
    void printTable() override;
};