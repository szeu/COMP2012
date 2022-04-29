#include <iostream>
#include "Toy.h"
using namespace std;

// TODO: complete the constructor of Toy
Toy::Toy(double regular_price,const string& character, const string& manufacturer) : 
Product(regular_price), character(character), manufacturer(manufacturer) {}
Toy::~Toy() {
    cout<<"Toy destructed"<<endl;
}
// TODO: complete Toy::get_character
string Toy::get_character() const {
    return character;
}
// TODO: complete Toy::get_manufacturer
string Toy::get_manufacturer() const {
    return manufacturer;
}
void Toy::print() const {
    cout<<"Toy: "<<endl;
    cout << "Character: "<<get_character() << ", Manufacturer: " <<get_manufacturer() << ", Retail Price: " << get_retail_price()<<endl;
}