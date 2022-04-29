#ifndef BST_H
#define BST_H

#include <iostream>
template <typename T> class BST
{
  private:
    struct BSTnode                                     // A node in a binary search tree
    {
        T value;
        int counter;
        BST left;                                      // Left sub-tree or called left child
        BST right;                                     // Right sub-tree or called right child
        BSTnode(const T& x) : value(x), counter(1) { } // Assume a copy constructor for T
        BSTnode(const BSTnode&) = default; // Copy constructor
        ~BSTnode() {}
    };

    BSTnode* root = nullptr;
    
  public:
    BST() = default;           
    ~BST() { delete root; }                                                  
    bool is_empty() const { return root == nullptr;}        // Bool function to check if the tree is empty
    void print(int depth = 0) const{
        if (is_empty())                 
          return;
        root->right.print(depth+1);      
        for (int j = 0; j < depth; j++) 
            std::cout << '\t';
        std::cout << '<' << root->value << ',' << root->counter << '>' << std::endl;
        root->left.print(depth+1);}                        // Print function
    const T& find_val() const { return root->value;}        // Accessor function to return the value of the root node
    void beKilled() {delete root; root=nullptr;}           // Called to kill the content of BST while retaining the root
    
    // TODO: Implement the following functions in respective cpp files
    BST(const BST& bst);                                    
    int getMaxHeight() const;                               
    int getMaxcounter() const;                              
    int totalNodes() const;                                 
    void insert(const T&);                                  
    bool breakbond(const T& x);                             
    void mutate();                                          
    void operator++(int);                                   
    const T& operator[](int) const;                         
    BST& operator=(const BST&);                             
    BST operator+(BST&);                              
};

#endif