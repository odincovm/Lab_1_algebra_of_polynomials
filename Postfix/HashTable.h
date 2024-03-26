#pragma once
#include "..\tables\AbstractTable.h"
#include "..\tables\myList.h"

class HashTable :
    public AbstractTable
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
    HashTable();
    ~HashTable();
    //virtual void sortTable();
    virtual void insert(std::string key, const Polynom& value); //  виртуальная функция для вставки
    virtual Polynom& search(std::string key); //  виртуальная функция для поиска
    virtual void remove(std::string key); //  виртуальная функция для удаления
    virtual void printTable();

    unsigned long long GetHash(string key);
    Node<Bucket*>* findInList(unsigned long long h);
};