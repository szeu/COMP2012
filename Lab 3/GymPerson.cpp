#include "GymPerson.h"
#include  <iostream>

using namespace std;

GymPerson::GymPerson(const string& name, const string& gender): name(name), gender(gender){}
string GymPerson::get_name() const {
    return name;
}
string GymPerson::get_gender() const {
    return gender;
}
void GymPerson::print() const {
    cout << "GymPerson: " <<endl;
    cout << "Name: " << get_name() << ", Gender: " << get_gender() << endl;
}
