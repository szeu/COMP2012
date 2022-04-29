#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Product.h"

using namespace std;

class Book : public Product {
    private: 
        string genre;
        string publisher;
        double discount;
    public:
        Book();
        Book(double regular_price, const string& product_name, const string& genre, const string& publisher, double discount);
        string get_genre() const;
        string get_publisher() const;
        double get_discount() const;
        double get_retail_price() const ;
        void print() const ;
};
#endif