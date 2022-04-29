#include "GymCoach.h"
#include <iostream>

using namespace std;

// TODO: complete the constructor of GymCoach
GymCoach::GymCoach(const string& name, const string& gender, float salary) : GymPerson(name, gender), salary(salary) {}

// TODO: complete GymCoach::coach
void GymCoach::coach(GymClass* coach_class) {
    this->coach_class = coach_class;
}
void GymCoach::print() const {
    cout << "GymCoach " << get_name() <<endl;
    cout<< "Gender: " << get_gender() << ", Salary: "<< salary << endl;
    cout<< "Coaching class: " <<endl;
    cout << "Name: " << coach_class->get_name() << ", Sports Type: " << coach_class->get_sports_type() << ", Period: " << coach_class->get_period() << ", Area: " << coach_class->get_area() << endl;
    cout<<endl;
}