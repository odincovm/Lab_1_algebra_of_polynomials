#pragma once
#include <string>
#include "Polynom.h"

class AbstractTable 
{
public:
    //virtual void sortTable() = 0;
    virtual void insert(std::string key, const Polynom& value) = 0; 
    virtual Polynom& search(const std::string& key) = 0; 
    virtual void remove(const std::string key) = 0;
    virtual void printTable() = 0;
};