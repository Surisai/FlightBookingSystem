#include "FlightInterface.h"

FlightInterface::FlightInterface() {
    manager.loadFromFile("data/flights.txt");
}

FlightInterface::~FlightInterface() {
    manager.saveToFile("data/flights.txt");
    std::cout << "\n💾 All data saved. Goodbye!\n";
}

void FlightInterface::displayMenu() const {
    std::cout << "\n====== ✈️ Flight Booking System ======\n";
    std::cout << "1. Create Flight\n";
    std::cout << "2. Delete Flight\n";
    std::cout << "3. Reserve Seats\n";
    std::cout << "4. Cancel Seats\n";
    std::cout << "5. Show All Flights\n";
    std::cout << "6. Exit\n";
    std::cout << "------------------------------------\n";
    std::cout << "Choose an option: ";
}

void FlightInterface::handleChoice(int choice) {
    int id, seats, capacity;

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
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "❌ Invalid option. Try again.\n";
    }
}

void FlightInterface::run() {
    int choice = 0;
    do {
        displayMenu();
        std::cin >> choice;
        handleChoice(choice);
    } while (choice != 6);
}
