//
// Created by ck on 2021/11/5.
//

#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

class BinarySearchTree
{
private:
    int id;
    BinarySearchTree *leftSubTree;
    BinarySearchTree *rightSubTree;
    
public:
    BinarySearchTree(int id);
    BinarySearchTree(const BinarySearchTree &other);
    ~BinarySearchTree();

    void add(int newId);
    bool hasId(int idToFind) const;
    int height() const;

    void printDFSPrefix() const;
    void printDFSInfix() const;
};

#endif