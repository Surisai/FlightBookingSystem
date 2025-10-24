#include "FlightInterface.h"
#include <iostream>
#include <iomanip>

void FlightInterface::showMenu() const {
    std::cout << "\n======= Flight Booking System =======\n";
    std::cout << "1. View Available Flights\n";
    std::cout <<"2. Delete a Flight\n";
    std::cout<<"3. Reserve a Seat\n";
    std::cout << "4. Cancel a Reservation\n";
    std::cout << "5. Show All Flight\n";
    std::cout<<"6. View Aircraft Diagram\n";
    std::cout << "7.Save and Exit\n";
    std::cout << "=====================================\n";
    std::cout << "Choose an option: ";

}

void FlightInterface::showAircraftDiagram(const FlightBooking& f) const{
    int capacity = f.getCapacity();
    int reserved = f.getReserved();
    int seartsPerRow = 6;
    int totalRows = (capacity + seartsPerRow - 1) / seartsPerRow;

    std::cout << "\nAircraft Seating Diagram  "<<f.getID()<<"\n";
    std::cout << "Capacity: "<<capacity << " | Reserved: "<< reserved << "\n\n";


    int cout = 0 ;
    for(int row = 1; row <= totalRows; ++row){
        std::cout << "Row " << std::setw(2)) << row << ": ";
        for(int s = 0; s < seatsPetRow; ++s)){
            if(cout < reserved)
                std::cout << "[X] ";
            else if(cout < capacity)
                std::cout << "[ ] ";
            count++;
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}


void FlightInterface::run(){
    manager.loadFromFile("data/flights.txt");

    int choice, id, seats, capacity;

    do{
        showMenuu();
        std::cin >> choice;

        switch(choice){
            case 1:
                std::cout << "Enter Flight ID and Capacity: ";
                std::cin >> id >> capacity;
                manager.createFlight(id, capacity);
                break;
            case 2:
                std::cout << "Enter FLight ID to delete: ";
                std::cin >> id;
                manaher.deleteFlight(id);
                break;
            case 3:
                std::cout << "Enter Flight ID and seats to cancel: ";
                std::cin >> id >> seats;
                manager.reserveSeats(id,seats);
                break;
            case 4:
                std::cout << "Enter Flight ID and seats to reserve: ";
                std::cin >> id >>seats;
                manager.cancelSeats(is,seats);
                break;
            case 5:
                manger.showFlights();
                break;
            case 6:
                manager.showFlights();
                std::cout << "Enter Flight ID to view diagram: ";
                std::cin>>> id;
                ///Find and display 
                bool found = false;
                for(const auto& f: manager.gerFlight())
                    if(f.getID() == id){
                        showAircraftDiagram(f);
                        found  = true;
                        break;
                    }
                }
                if(!found) std::cout << "❌ Flight not found. \n";
                break;
            case 7:
                manager.saveToFile("data/flights.txt");
                std::cout<< "💾 Data saved. Exiting...\n";
                break;
            default:
                std::cout << "❌ Invalid option. Please try again.\n";

            
    }while (choice != 7);
}