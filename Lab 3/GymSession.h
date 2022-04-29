#ifndef GYMSESSION_H
#define GYMSESSION_H

#include <string>

using namespace std;
class GymSession {
    private: 
        string period;
        string area;
    public:
        GymSession(const string& period, const string& area);
        string get_period() const;
        string get_area() const;
        void print() const;

};

#endif