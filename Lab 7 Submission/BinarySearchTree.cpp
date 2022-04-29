//
// Created by ck on 2021/11/5.
//

#include <iostream>

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(int id)
    : id(id), leftSubTree(nullptr), rightSubTree(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other): id(other.id)
{
    // TODO: Clone the two subtrees accordingly.
    id = other.id;
    (other.leftSubTree)?
    leftSubTree = new BinarySearchTree(*other.leftSubTree) : leftSubTree = nullptr;
    
    (other.rightSubTree)?
    rightSubTree = new BinarySearchTree(*other.rightSubTree) : rightSubTree = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    // TODO: release the resources occupied by the two subtrees if any.
    delete leftSubTree;
    delete rightSubTree;
}

void BinarySearchTree::add(int newId)
{
    // TODO: Insert the newId to the current tree.
    // You need to create a new node for the newId and attach it to the correct place.
    // Do nothing if the id is already in the tree.
    if(!hasId(newId)){
        if(newId < id){
            if(!leftSubTree)
                leftSubTree = new BinarySearchTree(newId);
            else
                leftSubTree->add(newId);
        }
        else{
            if(!rightSubTree)
                rightSubTree = new BinarySearchTree(newId);
            else
                rightSubTree->add(newId);
        }
    }
}

bool BinarySearchTree::hasId(int idToFind) const
{
    // TODO: Check whether the given id is in the tree.
    // You need to determinate whether to seach the left subtree or right subtree.
    bool have = false;

    if(id == idToFind)
        return true;

    if(leftSubTree && !have)
        have = leftSubTree->hasId(idToFind);
    if(rightSubTree && !have)
        have = rightSubTree->hasId(idToFind);

    return have;
}

int BinarySearchTree::height() const
{
    // TODO: Calculate the height of the tree.
    // Tree like this has height 0:
    //    O
    //
    // Trees like these have height 1:
    //    O        O       O
    //  /  \        \     /
    // O    O        O   O
    int counter = 0;
    int left_counter = 0;
    int right_counter = 0;

    if(!leftSubTree && !rightSubTree)
        return counter;

    if(leftSubTree)
        left_counter = leftSubTree->height();
    if(rightSubTree)
        right_counter = rightSubTree->height();

    (left_counter > right_counter)? counter = left_counter : counter = right_counter;
    return ++counter;
}

void BinarySearchTree::printDFSPrefix() const
{
    std::cout << id << " ";
    if (leftSubTree != nullptr)
        leftSubTree->printDFSPrefix();

    if (rightSubTree != nullptr)
        rightSubTree->printDFSPrefix();
}

void BinarySearchTree::printDFSInfix() const
{
    if (leftSubTree != nullptr)
        leftSubTree->printDFSInfix();
    std::cout << id << " ";
    if (rightSubTree != nullptr)
        rightSubTree->printDFSInfix();
}
