#include "../include/FlightBooking.h"

FlightBooking::FlightBooking(int id ,int capacity,int reserved)
: id(id), capacity(capacity), reserved(reserved) {}

//core func
bool FlightBooking::reserveSeats(int seats)
{
    if(reserved += seats <= capacity)
    {
        reserved += seats;
        return true;
    }
    return false;
}
bool FlightBooking::cancelSeats(int seats)
{
    if(reserved - seats >= 0)
    {
        reserved -= seats;
        return true;
    }

    return false;
}

//get 
int FlightBooking::getID() const {return id;}
int FlightBooking::getCapacity() const {return capacity;}
int FlightBooking::getReserved() const {return reserved;}

//display part
void FlightBooking::printStatus() const {
    if (id != 0) {
        double load = capacity ? (100.0 * reserved) / capacity : 0.0;
        std::cout << std::setw(10) << id
                  << std::setw(12) << capacity
                  << std::setw(12) << reserved
                  << std::setw(11) << std::fixed << std::setprecision(1) << load << "%\n";
    }
}
void FlightBooking::saveToFile(std::ofstream& out) const
{
    out << id <<" " << capacity << " " << reserved <<"\n";
}

FlightBooking FlightBooking::loadFromFile(std::ifstream& in)
{
    int id,capacity, reserved;
    if(in >> id >> capacity >> reserved )
        return FlightBooking(id,capacity,reserved);
    return FlightBooking();
}