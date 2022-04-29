#ifndef BOOK_H
#define BOOK_H

#include <string>
/* ======================================
    TODO: Complete the class declaration of Book
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
#include "Product.h"
class Book : public Product{
    private:
        string title;
        string genre;
        string publisher;
        double discount;
    public:
        Book(double regular_price, const string& title, const string& genre, const string&publisher, double discount);
        ~Book();
        string get_title() const;
        string get_genre() const;
        string get_publisher() const;
        double get_discount() const;
        double get_retail_price() const override;
        void print() const override;
};

#endif