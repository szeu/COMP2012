#include "bst.h"

template <typename T>
const T& BST<T>::operator[](int i) const
{
    // This function overloads operator[] whereby when value i is indexed, the (i+1)th smallest value is returned
    
    // Hint: remember to handle out of bound indexing
    int nodes = totalNodes();
    if(nodes == 1) return root->value;
    if(i > 0 && i >= nodes) i = i%nodes;
    if(i < 0 && i >= -1*nodes) i = nodes + i;
    if(i < 0 && i < -1*nodes){ i = (-1*i)%nodes; if(i != 0) i = nodes - i;} 
    
    int leftNodes = root->left.totalNodes();

    if(i == leftNodes) return root->value;

    if(i < leftNodes) return root->left[i];
    else return root->right[i-leftNodes-1];
}

template <typename T>
BST<T> BST<T>::operator+(BST<T>& bst)
{
    // This function overloads operator+, this serves to illustrate when two BSTs merge into one BST
    // or in Virus-Cell-Vaccine scenario, it is when the Virus consumes the Cell
    // When the virus tries to consume the cell, it first needs to check if it has a node with counter value of at least 4.
    // If yes, then the virus will consume the cell, and else the virus does NOT consume and temp object of the virus created is returned from the function.

    // Suppose virus BST is A and cell BST is B. when we do A + B, return a new BST such that it's node values
    // are the same as when you insert all B's nodes from smallest to largest
    // NOTE: You only need to add each value of B once, in another words, you can ignore the counter value associated with the nodes of B

    // Hint: you could consider taking advantage of operator[] if you have implemented it before this!
    BST<T> temp = *this;

    if(getMaxcounter() >= 4){
        int other_nodes = bst.totalNodes();

        for(int i = 0; i < other_nodes; i++)
            temp.insert(bst[i]);

        bst.beKilled();
    }
    return temp;
}   

template <typename T>
void BST<T>::operator++(int)
{
    // This function should increment counter value present in ALL nodes of the BST
    if(!root) return;
    
    if(root->left.root) root->left++;
    if(root->right.root) root->right++;
    
    root->counter++;
}

template <typename T>
BST<T>& BST<T>::operator=(const BST& bst)
{
    // This function should overload the operator= such that it carries out deepcopy
    (bst.root)? root = new BSTnode(*bst.root) : root = nullptr;
    return *this;
}