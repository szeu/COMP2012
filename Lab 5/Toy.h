#ifndef TOY_H
#define TOY_H

#include <string>
/* ===========================================================================
    TODO: Complete the class definition of Toy
    HINT: Remember to take the structure figure on the lab page as reference
          This class is an extended version of lab4 with modification.
   =========================================================================== */
#include "Product.h"
class Toy : public Product
{
    private:
        string manufacturer;
        bool is_limited_edition;
    public:
        Toy();
        Toy(double regular_price, const string& product_name, const string& manufacturer, const bool& is_limited_edition);
        string get_manufacturer() const;
        double get_retail_price() const override;
        void print() const override;
};
#endif
