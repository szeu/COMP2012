#ifndef GYMPERSON_H
#define GYMPERSON_H

#include <string>
using namespace std;

class GymPerson {
    private: 
        string name;
        string gender;
    public: 
        GymPerson(const string& name, const string& gender);
        string get_name() const;
        string get_gender() const;
        virtual void print() const;
};

#endif