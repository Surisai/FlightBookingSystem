#include "../include/FlightManager.h"
#include "../include/FlightBooking.h"

#include <iostream>
#include <iomanip>

void FlightManager::createFlight(int id,int capacity)
{
    for(const auto& f : flights)
    {
        if(f.getID() == id)
        {
            std::cout << "❌ Flight " << id << " already exists. \n";
            return ; // nothing
        }
    }
    flights.push_back(FlightBooking(id,capacity, 0));
    
    std::cout << "✅ Flight " << id << " created with capacity " << capacity << ".\n";

}
void FlightManager::deleteFlight(int id)
{
    for(auto it = flights.begin(); it != flights.end() ; it++)
    {
        if(it -> getID() == id)
        {
            flights.erase(it);
            std::cout<<"Flight " << id << "deledted.\n";
            return ;//nothing
        }
    }
    std::cout << "❌ Flight not found.\n";
}

void FlightManager::reserveSeats(int id, int seats)
{
    for(auto& f: flights){
        if(f.getID() == id){
            if(f.reserveSeats(seats))
                std::cout << "✅ Reserved " <<seats << "seats for flight " << id << ".\n";
            else
                std::cout <<"❌ Cannot reserve (may exceed capacity).\n";
            return;
        }
    }
    std::cout << "❌ Flight not found.\n";
}

void FlightManager::cancelSeats(int id, int seats)
{
    for(auto& f : flights){
        if(f.getID() == id){
            if(f.cancelSeats(seats))
                std::cout << "Canceled "<< seats << "seats for flight "<< id << ".\n";
            else
                std::cout << "Cannot cancel (invalid number).\n";
            return ;
        }   
    }
    std::cout << "❌ Flight not found.\n";
}

void FlightManager::showFlights() const
{
    if(flights.empty()){
        std::cout << "No flight in the system.\n";
        return ;
    }
    std::cout << "\n=================================================\n";
    std::cout <<"\n--------------------------------------------------\n";
    std::cout <<std::setw(10)<<"FlightID"
              <<std::setw(12)<<"Capacity"
              <<std::setw(12)<<"Revered"
              <<std::setw(12)<<"Load %" << std::endl; 
    std::cout <<"\n--------------------------------------------------\n";
    for(const auto& f: flights){
        f.printStatus();
    }
    std::cout <<"\n--------------------------------------------------\n";
}

void FlightManager::saveToFile(const std::string& filename) const
{
    //outfile
    std::ofstream out(filename);
    for(const auto& f: flights){
        f.saveToFile(out);
    }
    std::cout << "----📂 Data saved to " << filename << "----\n";
}
void FlightManager::loadFromFile(const std::string& filename) 
{
    std::ifstream in(filename);
    if(!in.is_open()){
        std::cout<< "📂 ⚠️ No saved data found. \n";
        return ;
    }
    flights.clear();
    while(!in.eof()){
        FlightBooking f = FlightBooking::loadFromFile(in);
        if(f.getID() != 0) flights.push_back(f);

    }
    in.close();
    std:: cout <<"📂 Data loaded from " << filename << "\n";
}