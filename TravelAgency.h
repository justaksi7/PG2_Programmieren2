#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>
#include <stdexcept>
#include "json.hpp"
#include "QString"
#include "Booking.h"
#include "FlightBooking.h"
#include "TrainTicket.h"
#include "HotelBooking.h"
#include "RentalCarReservation.h"

using namespace std;
using json=nlohmann::json;

class TravelAgency
{
public:
    std::vector<Booking*>Bookings;
public:
    Booking *returnBooking(int index);
    string returnmessage;
    bool errorDetected=false;
    TravelAgency(){}
    void readFile(QString infilename);
    ~TravelAgency()
    {
        for(const auto& Booking:Bookings)
        {
            delete Booking;
        }
    }
};
int findLine(string string1,string string2);
bool isAirport3Chars(string instring);
bool isPriceDouble(string instring);
#endif // TRAVELAGENCY_H
