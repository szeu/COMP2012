#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>
using std::cout; //we don't want to write "using namespace std;" here since we may include this file in many other files, and we don't want to affect all those files
                 //with "std::cout", we do not need to write "std::cout", just write "cout"

class Decimal
{
public:
    Decimal();
    Decimal(int input); 
    Decimal(const char* input); 
    Decimal(const Decimal& another);
    ~Decimal();

    bool isNegative() const;
    Decimal flipSign() const;
    bool isLargerThan(const Decimal& another) const;

    Decimal add(const Decimal& another) const;
    void addToSelf(const Decimal& another); 
    Decimal multiplyByPowerOfTen(int power) const;
    Decimal multiplyBySingleDigit(int multiplier) const;
    Decimal multiply(const Decimal& another) const;
    Decimal subtract(const Decimal& another) const;

    int countDigitsBeforeDP() const;
    int countDigitsAfterDP() const;

    void print() const //given
    { 
        cout << "\"";
        for(int i=0; i<size; i++)
            cout << content[i];
        cout << "\"";
        //cout << "size: " << size;
    };
private:
    char* content;
    int size;
};

#endif // DECIMAL_H