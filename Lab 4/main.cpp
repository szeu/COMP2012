#include <iostream>
#include "Book.h"
#include "Toy.h"

using namespace std;

int main() {
    Product* p1 = new Product(164.3);
    Product p2(243.3);
    Product* b1 = new Book(200.0, "Book 1", "Fiction", "ABC publisher", 0.8);
    Product p3 = *b1;
    Product* t1 = new Toy(105.4, "Unicorn", "CCC Manufacturer");
    Product p4 = *t1;
    p1->print();
    p2.print();
    b1->print();
    p3.print();
    t1->print();
    p4.print();
    cout << "Total Price: "<<endl;
    cout << p1->get_retail_price() + p2.get_retail_price() + b1->get_retail_price() + p3.get_retail_price() + t1->get_retail_price() + p4.get_retail_price()<<endl;
    delete p1;
    delete b1;
    delete t1;
}