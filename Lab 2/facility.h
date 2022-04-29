#ifndef FACILITY_H
#define FACILITY_H

class TennisBall
{
public:
    TennisBall();                           // Default constructor
    TennisBall(const TennisBall &other);    // Copy constructor
    ~TennisBall();                          // Destructor
};

class TennisCourt
{
public:
    TennisCourt();                          // Default constructor
    TennisCourt(const TennisCourt &other);  // Copy constructor
    ~TennisCourt();                         // Destructor
};


#endif