#ifndef BOOKING_H
#define BOOKING_H
#include <string>
#include <vector>
#include "json.hpp"

using namespace std;
using json=nlohmann::json;

class Booking
{
protected:
    std::string id;
    double price;
    std::string fromDate;
    std::string toDate;
public:
    string type;
    Booking(){}
    virtual std::string showDetails()=0;
    virtual ~Booking(){}
    string convertDate(string dateToConvert);
};

#endif // BOOKING_H
