#include <iostream>
#include "bst.h"
using namespace std;

template <typename T>          
bool BST<T>::breakbond(const T& x)
{
    // This function should find the first bond that exceeds the value of x, break it and return
    // If no such bond exists, then simply return
    // When implementing, take note of the following:
    // 1. Search from the leftmost branch and iteratively move to the rightmost branch (similar to how we search from smallest value in normal BST search)
    // 2. But take note! that this is trying to find the 'bond' which is the absolute value of the difference in value instead of the value itself!
    // 3. Upon finding the first bond that is greater than the function parameter value x, break the bond and return. Careful: Only break the first bond that meets this criteria
    // 4. breakbond function should return true when a bond has been broken otherwise return false
    
    // Hint: You could consider taking advantage of the boolean returned for recursive call
    int bond_strength;
    bool cut = false;

    if(!root) return false;

    if(!cut && root->left.root){
        bond_strength = root->value - root->left.root->value;
        if(bond_strength < 0) bond_strength*=-1;
        if(bond_strength > x){cut = true; delete root->left.root; root->left.root = nullptr;}
    }
    if(!cut && root->right.root){
        bond_strength = root->value - root->right.root->value;
        if(bond_strength < 0) bond_strength*=-1;
        if(bond_strength > x){ cut = true; delete root->right.root; root->right.root = nullptr; }
    }

    if(root->left.root && root->left.root->left.root && !cut) cut = root->left.breakbond(x);
    if(root->left.root && root->left.root->right.root && !cut) cut = root->left.breakbond(x);
    if(root->right.root && root->right.root->left.root && !cut) cut = root->right.breakbond(x);
    if(root->right.root && root->right.root->right.root && !cut) cut = root->right.breakbond(x);

    return cut;
}

template <typename T>
BST<T>::BST(const BST<T>& bst)
{
    // This function should perform deep-copy of one BST to another
    // (bst.root)? root = new BSTnode(*bst.root) : root = nullptr;
    *this = bst;
}

template <typename T>
int BST<T>::getMaxcounter() const
{
    // This function should find the maximum counter value of all the nodes present in BST
    int count = 0;
    int left_counter;
    int right_counter;
    
    if(root) count = root->counter; else return 0;

    if(root->left.root){
        left_counter = root->left.getMaxcounter();
        if(left_counter > count)
            count = left_counter;
    }
    if(root->right.root){
        right_counter = root->right.getMaxcounter();
        if(right_counter > count)
            count = right_counter;
    }
    return count;
}

template <typename T>
int BST<T>::getMaxHeight() const{
    // This function should return the maximum height of the BST
    int height = 0;
    int left_height = 0;
    int right_height = 0;

    if(!root) return 0;

    if(!root->left.root && !root->right.root) return ++height;

    if(root->left.root) left_height = root->left.getMaxHeight();
    if(root->right.root) right_height = root->right.getMaxHeight();

    (left_height > right_height)? height = left_height : height = right_height;
    return ++height;
}

template <typename T>          
void BST<T>::insert(const T& x)
{
    // This function inserts the given value into the BST
    // If the value to be inserted already exists in the BST, remember to handle the counter!
    if(!root){ root = new BSTnode(x); return; }

    if(root->value == x){ root->counter++; return; }
    
    if(x < root->value){
        if(!root->left.root) root->left.root = new BSTnode(x);
        else root->left.insert(x);
    }
    else if(x > root->value){
        if(!root->right.root) root->right.root = new BSTnode(x);
        else root->right.insert(x);
    }
}

template <typename T>
void BST<T>::mutate()
{
    // This function aims to mutate the virus such that it minimizes bond length while maintaining all the nodes
    // Write a function that reorders the nodes of the BST such that the bond length is minimized
    // This reordering can only occur if the height of the tree is at least 3. If less than 3, then do nothing.

    // NOTE: In the process of mutating, the virus BST loses information of its nodes' counter values.
    //       In another words, you do not need to worry about preserving the counter value when reordering the nodes!

    // Hint: 
    // 1. You could consider using operator[] if you have implemented it prior to this
    // 2. Suppose we have two nodes A and B. The bond length (difference between value of A and B) is minimal when
    //    there are no other nodes with value in between A and B. Hope this helps~
    if(getMaxHeight() >= 3){
        BST<T> temp;
        BST<T> temp_this = *this;
        int this_nodes = totalNodes();
        
        for(int i = 0; i < this_nodes; i++)
            temp.insert(temp_this[i]);

        delete root;
        *this = temp;
    }
}

template <typename T>
int BST<T>::totalNodes() const{

    // This function should return the total number of nodes present in the BST
    int num = 0;
    
    if(!root) return 0; else num++;

    if(root->left.root) num += root->left.totalNodes();
    if(root->right.root) num += root->right.totalNodes();
    return num;
}
