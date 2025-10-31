# Flight Booking System (C++)

## Overview
The **Flight Booking System** is a console-based application written in C++ that simulates the management of flight reservations. It demonstrates key object-oriented programming concepts such as:

- Classes and objects
- Encapsulation and data validation
- Inheritance and modular design
- File I/O for persistent storage
- Dynamic memory management and multiple object handling

This project was later planned to be integrated with a web interface using Crow and Boost.Asio.

---

## Features

1. **Flight Management**
   - Create new flights with unique IDs and specific capacities.
   - Delete flights from the system.
   - View all flights and their current reservation status.

2. **Reservation System**
   - Reserve seats for specific flights while respecting maximum allowed capacity.
   - Cancel reservations and update flight availability dynamically.
   - Prevent overbooking with input validation.

3. **Persistent Storage**
   - Save flight data to a file (`flights.txt`) for persistence.
   - Load flight data from a file on startup.

4. **Interactive Console Menu**
   - User-friendly menu with numbered options.
   - Immediate feedback on operations (success/error messages).

---

## Class Structure

### `FlightBooking`
- **Attributes:**
  - `id`: Unique flight identifier
  - `capacity`: Total number of seats available
  - `reserved`: Number of seats currently reserved
- **Functions:**
  - `reserveSeats(int seats)`
  - `cancelSeats(int seats)`
  - `printStatus()`
  - `getID()`

### `FlightManager`
- **Attributes:**
  - `flights`: A vector storing all `FlightBooking` objects
- **Functions:**
  - `createFlight(int id, int capacity)`
  - `deleteFlight(int id)`
  - `reserveSeats(int id, int seats)`
  - `cancelSeats(int id, int seats)`
  - `showFlights()`
  - `saveToFile(const std::string& filename)`
  - `loadFromFile(const std::string& filename)`

---

## How to Build and Run

1. **Clone or Download the Project**
   ```bash
   git clone <repository_url>
   cd Flight-Booking-System

2. **Compile the Code**
g++ main.cpp src/FlightBooking.cpp src/FlightInterface.cpp src/FlightManager.cpp -I include -o flightBooking

3. **Run the Application**
```bash
./flightBooking