#include <iostream>

#include "bookingsystem.h"

using namespace std;

int main()
{
    cout << "1. Initialize booking system!" << endl;
    BookingSystem bookingsystem(5,5,5);
    bookingsystem.log();

    cout << "\n2. Try to make a booking." << endl;
    bookingsystem.makeBooking();

    cout << "\n3. Try to release the resources including a tennis ball and a tennis court, and make a booking again" << endl;
    bookingsystem.releaseTennisBall();
    bookingsystem.releaseTennisCourt();
    bookingsystem.log();
    bookingsystem.makeBooking();
    bookingsystem.log();

    cout << "\n4. Release the resources including two tennis balls and a tennis court" << endl;
    bookingsystem.releaseTennisBall();
    bookingsystem.releaseTennisBall();
    bookingsystem.releaseTennisCourt();
    bookingsystem.log();

    cout << "\n5. It is a good behavior to back up your data." << endl;
    {
        BookingSystem backupBookingSystem = bookingsystem;
        backupBookingSystem.log();
        backupBookingSystem.releaseTennisCourt();
        backupBookingSystem.log();
        bookingsystem.log();
    }
    
    cout << "\n6. Destroy the booking system." << endl;
    bookingsystem.makeBooking();
    bookingsystem.log();
    BookingSystem bookingsystem2(3);
    bookingsystem2.log();
    cout << "Just before destruction... OK, let's do it." << endl;

    return 0;
} // "bookingsystem" is destructed once the program runs out of this scope.