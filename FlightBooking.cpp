#include "FlightBooking.h"
FlightBooking::FlightBooking(){type="FlightBooking";}
FlightBooking::FlightBooking(string inAirline,string inID,string inFromDate,string inToDate,
                             string inFromDest,string inToDest,double inPrice)
{
    airline=inAirline;id=inID;fromDate=inFromDate;toDate=inToDate;
    fromDestination=inFromDest;toDestination=inToDest;price=inPrice;
    type="FlightBooking";
}
void FlightBooking::setAirline(string inAirline)
{airline=inAirline;}
void FlightBooking::setFromDate(string inFromdate)
{fromDate=inFromdate;}
void FlightBooking::setFromDestination(string inFromDestination)
{fromDestination=inFromDestination;}
void FlightBooking::setID(string inID)
{id=inID;}
void FlightBooking::setPrice(double inPrice)
{price=inPrice;}
void FlightBooking::setToDate(string inToDate)
{toDate=inToDate;}
void FlightBooking::setToDestination(string inToDestination)
{toDestination=inToDestination;}
string FlightBooking::getAirline(){return airline;}
string FlightBooking::getFromDate(){return fromDate;}
string FlightBooking::getFromDestination(){return fromDestination;}
string FlightBooking::getID(){return id;}
string FlightBooking::getToDate(){return toDate;}
string FlightBooking::getToDestination(){return toDestination;}
double FlightBooking::getPrice(){return price;}

std::string FlightBooking::showDetails()
{
    string returnstring="Flugbuchung: \nID: "+id+"\nAirline: "+airline+"\nFrom: "+fromDestination+"\nTo: "+toDestination+"\nFrom date: "
                          +fromDate+"\nTo date: "+toDate+"\nPrice: "+to_string(price)+"\n";
    return returnstring;
}
