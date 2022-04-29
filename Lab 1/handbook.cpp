#include "handbook.h"
#include <iostream>
using namespace std;

Handbook::Handbook()
{
    cout << "Handbook" << endl << endl; 
    cout << "  On the ";
    Seafront seafront;
    cout << ":" << endl << "    ";
    Gym gym;
    cout << endl << "    ";
    Swimmingpool swimmingpool;
    cout << endl;
}
