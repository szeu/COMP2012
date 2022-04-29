#include <iostream>
#include "decimal.h"

using namespace std;

int main()
{
    int testCase = 1;

    cout << "Please enter the test case number: ";
    cin >> testCase;
    cout << endl;

    cout << "============================================" << endl;
    cout << "Showing the output for test case " << testCase << ":" << endl;

    if(testCase == 1) //test the default constructor
    {
        Decimal* zero = new Decimal;
        zero->print();
        cout << endl;
        delete zero;
    }

    else if(testCase == 2) //test the conversion constructor
    {
        Decimal* d = new Decimal("123456789876543212345678987654321");
        d->print();
        cout << endl;
        delete d;
    }
    else if(testCase == 3) //test the conversion constructor
    {
        Decimal* d = new Decimal("-123456789876543212345678987654321.132134513513123213312123123312312141244");
        d->print();
        cout << endl;
        delete d;
    }

    else if(testCase == 4) //test the conversion constructor
    {
        Decimal* d = new Decimal(1234);
        d->print();
        cout << endl;
        delete d;
    }
    else if(testCase == 5) //test the conversion constructor
    {
        Decimal* d = new Decimal(-1);
        d->print();
        cout << endl;
        delete d;
    }

    else if(testCase == 6) //test countDigitsBeforeDP and countDigitsAfterDP
    {
        Decimal* d = new Decimal("3.14");
        cout << "The number is ";
        d->print();
        cout << endl;
        cout << "countDigitsBeforeDP = " << d->countDigitsBeforeDP() << endl;
        cout << "countDigitsAfterDP = " << d->countDigitsAfterDP() << endl;
        delete d;
    }
    else if(testCase == 7) //test countDigitsBeforeDP and countDigitsAfterDP
    {
        Decimal* d = new Decimal("-1");
        cout << "The number is ";
        d->print();
        cout << endl;
        cout << "countDigitsBeforeDP = " << d->countDigitsBeforeDP() << endl;
        cout << "countDigitsAfterDP = " << d->countDigitsAfterDP() << endl;
        delete d;
    }

    else if(testCase == 8) //test isNegative
    {
        Decimal* a = new Decimal("12.345");
        cout << "Is 12.345 negative? ";
        cout << boolalpha << a->isNegative();
        cout << endl;
        delete a;
    }
    else if(testCase == 9) //test isNegative
    {
        Decimal* a = new Decimal("-12.345");
        cout << "Is -12.345 negative? ";
        cout << boolalpha << a->isNegative();
        cout << endl;
        delete a;
    }

    else if(testCase == 10) //test flipSign
    {
        Decimal* a = new Decimal("12.345");
        cout << "Flip 12.345: ";
        a->flipSign().print();
        cout << endl;
        delete a;
    }
    else if(testCase == 11) //test flipSign
    {
        Decimal* a = new Decimal("-12.345");
        cout << "Flip -12.345: ";
        a->flipSign().print();
        cout << endl;
        delete a;
    }

    
    else if(testCase == 12) //test isLargerThan
    {
        Decimal* b = new Decimal("-9.1");
        Decimal* a = new Decimal("-9.2");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }

    else if(testCase == 39) //test countDigits
    {
        Decimal* b = new Decimal("-9.1");
        Decimal* a = new Decimal("-9.2");
        cout << a->countDigitsBeforeDP() << endl;
        cout << a->countDigitsAfterDP() << endl;
        cout << b->countDigitsBeforeDP() << endl;
        cout << b->countDigitsAfterDP() << endl;
        delete a;
        delete b;
    }

    else if(testCase == 13) //test isLargerThan
    {
        Decimal* b = new Decimal("12.345");
        Decimal* a = new Decimal("12.945");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 14) //test isLargerThan
    {
        Decimal* b = new Decimal("12.345");
        Decimal* a = new Decimal("9.345");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }

    else if(testCase == 15) //test isLargerThan
    {
        Decimal* b = new Decimal("12.9");
        Decimal* a = new Decimal("12.345");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 16) //test isLargerThan
    {
        Decimal* b = new Decimal("0");
        Decimal* a = new Decimal("0.0000001");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }



    else if(testCase == 17) //test add
    {
        Decimal* a = new Decimal("123412312312312.123");
        Decimal* b = new Decimal("87546687450968405968");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }

    else if(testCase == 0) //test add
    {
        Decimal* a = new Decimal("5.2");
        Decimal* b = new Decimal("4.8");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }

    else if(testCase == 18) //test add
    {
        Decimal* a = new Decimal("-10");
        Decimal* b = new Decimal("10");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 19) //test add
    {
        Decimal* a = new Decimal("12.9");
        Decimal* b = new Decimal("-6.2");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 20) //test add
    {
        Decimal* b = new Decimal("12");
        Decimal* a = new Decimal("6.78");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 21) //test add
    {
        Decimal* a = new Decimal("98.919");
        Decimal* b = new Decimal("-2.34");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }


    else if(testCase == 22) //test addToSelf
    {
        Decimal* a = new Decimal("12.345");
        Decimal* b = new Decimal("6");
        a->addToSelf(*b);
        cout << "a has been updated to ";
        a->print();
        cout << endl;
        delete a;
        delete b;
    }


    else if(testCase == 23) //test deep copy
    {
        Decimal* a = new Decimal("12");
        Decimal* c = new Decimal(*a);
        cout << "a is "; a->print(); cout << endl;
        cout << "c (deep copy of a) is "; c->print(); cout << endl;
        delete a;
        cout << "after deleting a, c (deep copy of a) is "; c->print(); cout << endl;
        delete c;
        cout << "both deleted. no crash! wow. amaze." << endl;
    }


    else if(testCase == 24) //test timesTenPower
    {
        Decimal* a = new Decimal("0.345");
        a->print();
        cout << " * 100 = ";
        a->multiplyByPowerOfTen(2).print();
        cout << endl;
        delete a;
    }
    
    else if(testCase == 25) //test timesTenPower
    {
        Decimal* a = new Decimal("-12345.000000000000000000000000012345");
        a->print();
        cout << " * 1000000000000 = ";
        a->multiplyByPowerOfTen(12).print();
        cout << endl;
        delete a;
    }


    else if(testCase == 26) //test multiplyBySingleDigit
    {
        Decimal* a = new Decimal("0.0005");
        a->print();
        cout << " * 2 = ";
        a->multiplyBySingleDigit(2).print(); 
        cout << endl;
        delete a;
    }
    else if(testCase == 27) //test multiplyBySingleDigit
    {
        Decimal* a = new Decimal("12.345");
        a->print();
        cout << " * 9 = ";
        a->multiplyBySingleDigit(9).print(); 
        cout << endl;
        delete a;
    }
    else if(testCase == 28) //test multiplyBySingleDigit
    {
        Decimal* a = new Decimal("716238721637812637123687123621378612388127638761283");
        a->print();
        cout << " * 9 = ";
        a->multiplyBySingleDigit(9).print(); 
        cout << endl;
        delete a;
    }



    else if(testCase == 29) //test multiply
    {
        Decimal* a = new Decimal("12.345");
        Decimal* b = new Decimal("6.78");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 30) //test multiply
    {
        Decimal* a = new Decimal("12");
        Decimal* b = new Decimal("-6");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 31) //test multiply
    {
        Decimal* a = new Decimal("12.345");
        Decimal* b = new Decimal("10000");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 32) //test multiply
    {
        Decimal* b = new Decimal("0.5");
        Decimal* a = new Decimal("2");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 33) //test multiply
    {
        Decimal* b = new Decimal("12999999999999999999999999999999999.999999999999999999999999999999999345");
        Decimal* a = new Decimal("-9999999999999999999999999999999996");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }


    else if(testCase == 34) //test subtract
    {
        Decimal* a = new Decimal("-9.9");
        Decimal* b = new Decimal("10");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 35) //test subtract
    {
        Decimal* a = new Decimal("-8.9");
        Decimal* b = new Decimal("2.67");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 36) //test subtract
    {
        Decimal* b = new Decimal("233.66");
        Decimal* a = new Decimal("3.66");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 37) //test subtract
    {
        Decimal* b = new Decimal("1");
        Decimal* a = new Decimal("2");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 38) //test subtract
    {
        Decimal* b = new Decimal("29.99");
        Decimal* a = new Decimal("29.99");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }



    cout << "============================================" << endl << endl;

    return 0;
}
