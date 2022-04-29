#include "GymSession.h"
#include <iostream>
using namespace std;

GymSession::GymSession(const string& period, const string& area) : period(period), area(area) {}
string GymSession::get_period() const {
    return period;
}
string GymSession::get_area() const {
    return area;
}
void GymSession::print() const {
    cout << "GymSession: "<<endl;
    cout << "Period: " << get_period() << ", Area: " << get_area() << endl;
}