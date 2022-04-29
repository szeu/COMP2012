#ifndef GYMCLASS_H
#define GYMCLASS_H

/* ======================================
    TODO: Complete the class declaration of GymClass
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/
#include "GymSession.h"
class GymClass : public GymSession {
    private: 
        string name;
        string sports_type;
    public:
        GymClass(const string& period, const string& area, const string& name, const string& sports_type);
        string get_name() const;
        string get_sports_type() const;
        void print() const;

};

#endif