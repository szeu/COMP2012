#include <iostream>

#include "facility.h"

using namespace std;

// TennisBall
TennisBall::TennisBall()
{
    cout << "TennisBall Constructed!" << endl; 
}

TennisBall::TennisBall(const TennisBall & other)
{
    cout << "TennisBall Copied!" << endl;
}

TennisBall::~TennisBall()
{
    cout << "TennisBall Destructed!" << endl;
}

//TennisCourt
TennisCourt::TennisCourt()
{
    cout << "TennisCourt Constructed!" << endl; 
}

TennisCourt::TennisCourt(const TennisCourt & other)
{
    cout << "TennisCourt Copied!" << endl;
}

TennisCourt::~TennisCourt()
{
    cout << "TennisCourt Destructed!" << endl;
}