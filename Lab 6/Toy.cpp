#include <iostream>
#include "Toy.h"
using namespace std;
Toy::Toy(): Product(0, ""), manufacturer(""), is_limited_edition(false){}

Toy::Toy(double regular_price, const string& product_name, const string& manufacturer, const bool& is_limited_edition) : Product(regular_price, product_name), manufacturer(manufacturer), is_limited_edition(is_limited_edition) {}

string Toy::get_manufacturer() const {
    return manufacturer;
}
double Toy::get_retail_price() const {
    if(is_limited_edition)
    {
        return get_regular_price() * 2;
    }
    else
    {
        return get_regular_price();
    }
}    
void Toy::print() const {
    cout<<"Toy: "<<endl;
    cout << "Product name: "<<get_product_name() << ", Manufacturer: " <<get_manufacturer() << ", Retail Price: " << get_retail_price()<<endl;
}