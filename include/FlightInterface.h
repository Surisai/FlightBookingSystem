#ifndef FLIGHTINTERFACE_H
#define FLIGHTINTERFACE_H

#include "FlightManager.h"

class FlightInterface {
    private:
        FlightManager manager;

      
    public:
        FlightInterface();
        ~FlightInterface();

        void run(); // Main menu loop
        void displayMenu() const;
        void handleChoice(int choice);
    };
#endif