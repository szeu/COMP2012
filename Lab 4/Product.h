#ifndef PRODUCT_H
#define PRODUCT_H

/* ======================================
    TODO: Complete the class declaration of Product
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
using namespace std;
class Product{
    private:
        double regular_price;
    public:
        Product(double regular_price);
        virtual ~Product();
        double get_regular_price() const;
        virtual double get_retail_price() const;
        virtual void print() const;
};

#endif