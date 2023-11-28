#ifndef TRAINTICKET_H
#define TRAINTICKET_H
#include "Booking.h"

class TrainTicket :public Booking
{
private:
    std::string fromDestination;
    std::string toDestination;
    std::string departureTime;
    std::string arrivalTime;
    std::vector<std::string>connectingStations;
public:
    void setID(string inID);
    void setPrice(double inPrice);
    void setFromDate(string inFromdate);
    void setToDate(string inToDate);
    void setFromStation(string inFromStation);
    void setToStation(string inToStation);
    void setDepartureTime(string inDepartureTime);
    void setArrivalTime(string inArrivalTime);
    void setConnectingStations(vector<string>inConnectingStations);
    string getID();
    double getPrice();
    string getFromDate();
    string getToDate();
    string getFromStation();
    string getToStation();
    string getDepartureTime();
    string getArrivalTime();
    string getConnectingStations();
    TrainTicket();
    TrainTicket(string inID,string inFromDate,string intoDate,double inPrice,string inFromStation,string inToStation,
                string inArrivalTime,string inDepartureTime,vector<string>inConnectingStations);
    std::string showDetails();
    ~TrainTicket(){}
};

#endif // TRAINTICKET_H
