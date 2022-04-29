//
// Created by ck on 2021/11/5.
//

#include <map>
#include <string>
#include <iostream>
#include <algorithm>

#include "Manager.h"

using namespace std;

BinarySearchTree* Manager::getSection(string sectionType)
{
    // TODO: Lookup the managerRegistry to get the corresponding section instance for the given sectionType
    // map<std::string, BinarySearchTree*>::iterator i = find(managerRegistry.begin(), managerRegistry.end(), sectionType);
    return managerRegistry.at(sectionType);
}

void Manager::registerSection(string sectionType, BinarySearchTree* sectionInstance)
{
    // TODO: Modify the managerRegistry to associate the sectionType with the managerRegistry
    managerRegistry.emplace(sectionType, sectionInstance);
}

void Manager::deleteSection(string sectionType)
{
    // TODO: Delete the section of sectionType and its corresponding key in the managerRegistry
    managerRegistry.erase(sectionType);
}

void Manager::printStatus()
{
    cout << "Maneger has " << managerRegistry.size() << " sections" << (managerRegistry.size() != 0 ? ":" : "");
    if (managerRegistry.size() != 0){
        // TODO: print the types of all the registered sections
        // You are NOT ALLOWED to use a for loop or a while loop
        // You may the for_each function (http://www.cplusplus.com/reference/algorithm/for_each/) to complete this task
        // Hint: It can be done using a single line of code
        // Hint2: The type of the elements in a map<A,B> is pair<A,B>
        // Hint3: You just need to print the sectionType of each registered section separated by a space 
        // (e.g., Maneger has 2 sections: book toy)
        for_each(managerRegistry.begin(), managerRegistry.end(), [](pair<string, BinarySearchTree*> p){cout << " " << p.first;});
    }   
}

Manager::~Manager()
{
    // TODO: Release all the sections in managerRegistry by using delete statement
    // You are NOT ALLOWED to use a for loop or a while loop
    // You may the for_each function (http://www.cplusplus.com/reference/algorithm/for_each/) to complete this task
    // Hint: It can be done using a single line of code
    // Hint2: The type of the elements in a map<A,B> is pair<A,B>
    for_each(managerRegistry.begin(), managerRegistry.end(), [](pair<string, BinarySearchTree*> p){delete p.second;});
}

// void print(pair<string, BinarySearchTree*>& p){cout << p.first;}
// void del(pair<string, BinarySearchTree*>& p){delete p.second;}


