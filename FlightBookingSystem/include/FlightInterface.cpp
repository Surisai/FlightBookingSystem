#ifndef FLIGHTINTERFACE_H
#define FLIGHTINTERFACE_H

#include "FlightManager.h"

class FlightInterface {
    private:
        FlightManager manager;

        void showAirplaneGraphic() const;
        void displayMenu() const;
    public:
        void run();///main loop 
};
#endif