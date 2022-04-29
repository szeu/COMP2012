#include <iostream>
using namespace std;
#include "bst.h"
#include "tree_functions.cpp"
#include "operator_overloading.cpp"

int main(){
    int testCase = 1;
    cout << "Please enter the test case number: ";
    cin >> testCase;
    cout << endl;

    cout << "============================================" << endl;
    cout << "Showing the output for test case " << testCase << ":" << endl;

    if (testCase==1){
        int virus_sequence[] = {1,4,2,6};
        BST<int> virus_tree;
        for (int i = 0; i<4; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        cout<<endl;
        cout<<"Step 1: Tree output after adding nodes with values: 1, 4, 2, 6"<<endl;
        cout<<endl;
        virus_tree.print();
        cout<<endl;
        cout<<"Step 2: Tree output after adding nodes with values: 1, 4"<<endl;
        cout<<endl;
        int virus_sequence2[] = {1,4};
        for (int i = 0; i<2; i++){
            virus_tree.insert(virus_sequence2[i]);
        }
        virus_tree.print();
        cout<<endl;

    }
    else if (testCase==2){
        // Testing getMaxHeight function
        int virus_sequence[] = {1,4,5,2,3,8,9};
        BST<int> virus_tree;
        for (int i = 0; i<7; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Maximum height of the tree: "<<virus_tree.getMaxHeight()<<endl;
    }
    else if (testCase==3){
        // Testing getMaxCounter function
        int virus_sequence[] = {1,2,2,3,3,3,4,5,5,6};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Maximum counter present in the tree: "<<virus_tree.getMaxcounter()<<endl;
    }
    else if (testCase==4){
        // Testing totalNodes function
        int virus_sequence[] = {1,2,2,3,3,3,4,5,5,6};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Total number of nodes in the tree: "<<virus_tree.totalNodes()<<endl;
    }
    else if (testCase==5){
        // Testing breakbond function
        int virus_sequence[] = {4,2,5,3,1,4,3,3,2,9};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout<<"Breaking bond with strength 2"<<endl;

        // Vaccine of strength 2 in action
        virus_tree.breakbond(2);
        virus_tree.print();
    }
    else if (testCase==6){
        // Testing copy constructor and operator=
        int virus_sequence[] = {4,2,5,3,1,4,3,3,2,9};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        // BST<int> clone_virus_tree(virus_tree);   // copy constructor
        BST<int> clone_virus_tree = virus_tree;
        virus_tree.print();
        clone_virus_tree.print();
    }
    else if (testCase==7){
        // Testing operator++
        int virus_sequence[] = {4,2,5,3,1,4,3,3,2,9,8};
        BST<int> virus_tree;
        for (int i = 0; i<11; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        virus_tree++;
        virus_tree.print();
    }
    else if (testCase==8){
        // Testing operator[]
        int virus_sequence[] = {5,2,5,3,4,3,3,2,9,8,11,4,7};
        BST<int> virus_tree;
        for (int i = 0; i<13; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        cout << "The 8th smallest node is " << virus_tree[-15] << endl;
    }
    else if (testCase==9){
        // Testing operator+
        int virus_sequence[] = {5,2,5,3,4,3,3,2,9,8,11,4,7,3};
        BST<int> virus_tree;
        for (int i = 0; i<14; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        int cell_sequence[] = {2,9,8,11,4,7,3,1,10};
        BST<int> cell_tree;
        for (int i = 0; i<9; i++){
            cell_tree.insert(cell_sequence[i]);
        }
        cout << "virus: " << endl;
        virus_tree.print();
        cout << endl;
        cout << "cell: " << endl;
        cell_tree.print();
        cout << endl;
        cout << "result: " << endl;
        BST<int> result = virus_tree + cell_tree;
        result.print();
    }
    else if (testCase==10){
        // Testing mutate function
        int virus_sequence[] = {4,2,5,3,1,4,3,3,2,9};
        BST<int> virus_tree;
        for (int i = 0; i<10; i++){
            virus_tree.insert(virus_sequence[i]);
        }
        virus_tree.print();
        virus_tree.mutate();
        virus_tree.print();
        cout<<"Breaking bond with strength 2"<<endl;

        // Vaccine of strength 2 in action
        virus_tree.breakbond(2);
        virus_tree.print();
    }
    cout << "============================================" << endl << endl;
    return 0;
}

