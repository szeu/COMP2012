//
// Created by ck on 2021/11/5.
//

#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <string>

#include "BinarySearchTree.h"

class Manager
{
private:
    std::map<std::string, BinarySearchTree*> managerRegistry;

public:
    BinarySearchTree* getSection(std::string sectionType);
    void registerSection(std::string sectionType, BinarySearchTree* sectionInstance);
    void deleteSection(std::string sectionType);
    void printStatus();
    ~Manager();
};

#endif
