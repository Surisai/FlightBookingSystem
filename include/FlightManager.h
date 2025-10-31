#ifndef FLIGHTMANAGER_H
#define FLIGHTMANAGER_H

#include <vector>
#include <string>
#include <fstream>
#include "FlightBooking.h"

class FlightManager
{
    private:
        std::vector<FlightBooking> flights;
    public:
        //
        const std::vector<FlightBooking>& getFlights() const { return flights;}
        //main function 
        void createFlight(int id, int capacity);
        void deleteFlight(int id);
        void reserveSeats(int id, int seats);
        void cancelSeats(int id, int seats);
        void showFlights() const;

        //assistan
        void saveToFile(const std::string& filename) const ;
        void loadFromFile(const std::string& filename);
};
#endif

