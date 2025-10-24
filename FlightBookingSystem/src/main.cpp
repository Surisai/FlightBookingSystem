#include "FlightManager.h"
#include <iostream>


int main() {
     FlightManager manager;
    manager.loadFromFile("data/flights.txt");

    int choice, id, seats, capacity;

    do {
        std::cout << "\n====== ✈️ Flight Booking System ======\n";
        std::cout << "1. Create Flight\n";
        std::cout << "2. Delete Flight\n";
        std::cout << "3. Reserve Seats\n";
        std::cout << "4. Cancel Seats\n";
        std::cout << "5. Show All Flights\n";
        std::cout << "6. Save and Exit\n";
        std::cout << "------------------------------------\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Flight ID and Capacity: ";
                std::cin >> id >> capacity;
                manager.createFlight(id, capacity);
                break;
            case 2:
                std::cout << "Enter Flight ID to delete: ";
                std::cin >> id;
                manager.deleteFlight(id);
                break;
            case 3:
                std::cout << "Enter Flight ID and number of seats to reserve: ";
                std::cin >> id >> seats;
                manager.reserveSeats(id, seats);
                break;
            case 4:
                std::cout << "Enter Flight ID and number of seats to cancel: ";
                std::cin >> id >> seats;
                manager.cancelSeats(id, seats);
                break;
            case 5:
                manager.showFlights();
                break;
            case 6:
                manager.saveToFile("data/flights.txt");
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    } while (choice != 6);

    FlightInterface app;
    app.run();
    return 0;
}
