#include "GymSession.h"
#include "GymClass.h"
#include "GymPerson.h"
#include "GymStudent.h"
#include "GymCoach.h"
#include <iostream>
using namespace std;

int main() {
    GymClass class1("Tue 1-2pm", "Yoga Room 1", "Yoga lv.1", "Yoga");
    GymClass class2("Sat 5-6pm", "Room 4", "Gymnastics lv. 1", "Gymnastics");
    GymSession sess1("Sun 10-11am", "Lifting Zone");
    GymCoach coach1("Harry", "Male", 10000);
    GymCoach coach2("Tom", "Male", 12000.2);
    coach1.coach(&class1);
    coach2.coach(&class2);
    GymStudent student1("Ron", "Male");
    student1.join_session(&class1);
    student1.join_session(&sess1);
    student1.join_session(&class2);
    cout << "All GymSession :" << endl;
    GymSession sess2 = class1;
    GymSession sess3 = class2;
    sess1.print();
    sess2.print();
    sess3.print();
    cout << "All GymPeron: "<< endl;
    GymPerson* pers1 = &coach1;
    GymPerson* pers2 = &coach2;
    GymPerson* pers3 = &student1;
    pers1->print();
    pers2->print();
    pers3->print();

}