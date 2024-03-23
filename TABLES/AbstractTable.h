#pragma once
#include <string>
#include "Polynom.h"

class AbstractTable {
public:
    virtual void sortTable() = 0;
    virtual void insert(std::string key, const Polynom& value) = 0; //  виртуальная функция для вставки
    virtual Polynom& search(std::string key) = 0; //  виртуальная функция для поиска
    virtual void remove(std::string key) = 0; //  виртуальная функция для удаления
    virtual void printTable() = 0;
};