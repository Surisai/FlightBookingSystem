#include "FlightBooking.h"
#include <vector>
#include <memory>
#include <iostream>

int main() {
    std::vector<std::unique_ptr<iBooking>> bookings;
    bookings.push_back(std::make_unique<FlightBooking>(1,400,500));
    bookings.push_back(std::make_unique<FlightBooking>(2,250,900));

    for(const auto& b : bookings)
    {
        b->printStatus();
    }

    bookings[0]->reserveSeats(30);
    bookings[1]->cancelSeats(50);

    std::cout << "\nAfter updates: \n";
    for(const auto& b : bookings)
    {
        b->printStatus();
    }
    return 0;
}
