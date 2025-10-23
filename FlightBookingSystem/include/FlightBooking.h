#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

// #include "iBooking.h"
#include <iostream>
#include <fstream>
#include <iomanip>

class FlightBooking 
{
    private:
        int id;
        int capacity;
        int reserved;
    public:
        FlightBooking(int id = 0 , int capacity = 0 , int reserved = 0);
       //Core function 
        bool reserveSeats(int seats);
        bool cancelSeats(int seats) ;
        void printStatus () const ;

        //Accessors
        int getID() const;
        int getCapacity() const ;
        int getReserved() const;
    
        //void printAirplaneGraphic() const; //feature aircraft plant

        //Persistence
        void saveToFile (std::ofstream& out) const;
        static FlightBooking loadFromFile(std::ifstream& in);

        
};

#endif