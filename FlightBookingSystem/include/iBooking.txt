#ifndef IBOOKING_H
#define IBOOKING_H

#include <string>

class iBooking
{
    public:
    //magic upgrade on real object point to 'virtual
    virtual void printStatus() const = 0;
    virtual bool reserveSeats(int seats) = 0;
    virtual bool cancelSeats(int seats) = 0;
    virtual int getId() const = 0;
    //free memory from child
    virtual ~iBooking() = default;
};

#endif