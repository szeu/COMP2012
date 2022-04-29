#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include "facility.h"
#include "person.h"



class BookingSystem
{
    static int nextID; 
private:
    TennisBall **tennisballs;
    TennisCourt **tenniscourts;
    Person **persons;
    
    int numTennisBall;      // Current number of TennisBall.
    int numTennisCourt;     // Current number of TennisCourt.
    int numPerson;          // Current number of Person(user).
    
    int maxNumTennisBall;   // Maximum number of TennisBall.
    int maxNumTennisCourt;  // Maximum number of TennisCourt.
    int maxNumPerson;       // Maximum number of Person(user).
    int SN;                 // Series number
public:
    // TODO: Type conversion constructor
    BookingSystem(int capacity); 
    // TODO: Other constructor
    BookingSystem(int nTennisBall, int nTennisCourt, int capacity); 
    // TODO: Copy constructor
    BookingSystem(const BookingSystem &other);
    // TODO: Destructor
    ~BookingSystem();

    // TODO: a tennis ball is available by allocating a TennisBall object
    void releaseTennisBall();
    // TODO: a tennis court is available by allocating a TennisCourt object
    void releaseTennisCourt();
    // TODO: accept person's booking by allocating a Person object. 
    // The person would like to reserve a tennis basll and a tennis court.
    void makeBooking(); 

    // print the log
    void log() const; 
};

#endif