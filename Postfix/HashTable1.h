#pragma once
#include "../Project1/AbstractTable.h"
#include "../Project1/myList.h"

class HashTable1: public AbstractTable
{
    typedef struct KeyValuePair {
        string key;
        Polynom value;
    } KeyValuePair;

    typedef struct Bucket {
        unsigned long long key;
        myList<KeyValuePair> chain;
    } Bucket;

    myList<Bucket*> buckets;

    int count;

public:
    HashTable1();
    ~HashTable1();
    void insert(std::string key, const Polynom& value) override; //  виртуальная функция для вставки
    Polynom& search(const std::string& key) override; //  виртуальная функция для поиска
    void remove(std::string key) override; //  виртуальная функция для удаления
    void printTable() override;

    unsigned long long GetHash(string key);
    Node<Bucket*>* findInList(unsigned long long h);
};