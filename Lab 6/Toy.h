#ifndef TOY_H
#define TOY_H

#include <string>
#include "Product.h"

using namespace std;

class Toy : public Product{
    private: 
        string manufacturer;
        bool is_limited_edition;
    public: 
        Toy();
        Toy(double regular_price, const string& product_name, const string& manufacturer, const bool& is_limited_edition);
        string get_manufacturer() const;
        double get_retail_price() const ;
        void print() const ;
};
#endif