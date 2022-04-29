#include <iostream>
#include "Product.h"


using namespace std;

// TODO: complete the constructor of Product
Product::Product(double regular_price){this->regular_price = regular_price;}

Product::~Product() {
    cout <<"Product destructed" <<endl;
}

// TODO: complete Product::get_regular_price
double Product::get_regular_price() const {
    return regular_price;
}
// TODO: complete Product::get_retail_price
double Product::get_retail_price() const{
    return regular_price;
}

void Product::print() const {
    cout<<"Product: "<<endl;
    cout<<"Price: "<<get_retail_price()<<endl; 
}