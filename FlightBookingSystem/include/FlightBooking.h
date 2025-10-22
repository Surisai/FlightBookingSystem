#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOLING_H

#include "iBooking.h"
#include <iostream>
class FlightBooking : public iBooking
{
    private:
        int id;
        int capacity;
        int reserved;
    public:
        FlightBooking(int id = 0 , int capacity = 0 , int reserved = 0);
        void printStatus () const override;
        bool reserveSeats(int seats) override ;
        bool cancelSeats(int seats) override;
        int getId( ) const override { return id;} 
};

#endif