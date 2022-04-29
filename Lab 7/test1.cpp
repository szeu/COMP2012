//
// Created by ck on 2021/11/5.
//

#include <vector>
#include <string>
#include <iostream>

#include "Manager.h"
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Manager manager = Manager();
    BinarySearchTree *sec1 = new BinarySearchTree(6);
    manager.registerSection("book", sec1);
    manager.printStatus();
    cout << endl;

    for (int i : vector<int>{11, 9, 9, 10, 16, 15, 13, 4, 1, 3})
        sec1->add(i);

    cout << "The height of section #1 is: " << sec1->height() << endl;
    cout << "Section #1 prefix notation: ";
    sec1->printDFSPrefix();
    cout << endl;
    cout << "Section #1 infix notation: ";
    sec1->printDFSInfix();
    cout << endl;
    cout << "11 is " << (sec1->hasId(11) ? "" : "not ") << "in Section #1" << endl;
    
    BinarySearchTree *sec2 = new BinarySearchTree(*sec1);
    manager.registerSection("toy", sec2);
    cout << "Manager is deleting the book section" << endl;
    manager.deleteSection("book");
    manager.printStatus();
    
    return 0;
}
