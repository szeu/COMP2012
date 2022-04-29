#ifndef PERSON_H
#define PERSON_H

#include "facility.h"

class Person
{
private:
    TennisBall *tennisball;
    TennisCourt *tenniscourt;

public:
    Person(TennisBall *tennisball, TennisCourt *tenniscourt); //TODO: Other constructor.
    Person(const Person &other);    //TODO: Copy constructor, deep copy objects.
    ~Person();                      //TODO: Destructor
};
#endif