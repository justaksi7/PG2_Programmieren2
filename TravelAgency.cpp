#include "TravelAgency.h"

bool isPriceDouble(string instring)
{
    double num;
    istringstream ss(instring);
    ss>>num;
    if(ss.fail())
    {
        return false;
    }
    else{
        return true;}
}

bool isAirport3Chars(string instring)
{
    bool ischar=true;
    if(instring.size()!=3)
    {
        ischar=false;
    }
    bool smallchar=false;
    bool capitalchar=false;
    for(char ch: instring)
    {
        if(ischar==true)
        {
        if((ch>=60 && ch<=90))
        {
            smallchar=true;
        }
        else if((ch>=97&&ch<=122))
        {
            capitalchar=true;
        }
        if(smallchar==false && capitalchar==false)
        {
            ischar=false;
        }
        }
        smallchar=false;
        capitalchar=false;
    }
    return ischar;
}

int findLine(string string1,string string2)
{
    ifstream file("bookings.json");
    string line;
    file.close();
    int linecount=0;
    while(!file.eof())
    {
        getline(file,line);
        linecount++;
        if(line.find(string1)!=line.npos&&line.find(string2)!=line.npos)
        {
            return linecount;
            break;
        }
    }

}

void TravelAgency::readFile(QString infilename)
{
    int traincounter=0;double trainprice=0;
    int hotelcounter=0;double hotelprice=0;
    int carcounter=0;double carprice=0;
    int flightcounter=0;double flightprice=0;
    int jsonObjectCounter=0;
    int jsonObjectError=0;
    bool readSuccesful=true;
    std::ifstream file(infilename.toStdString());
    if (!file.is_open()) {
        returnmessage="JSON-Datei konnte nicht geöffnet werden!";
    }
    json jsonArray;
    file>>jsonArray;
    file.close();
    std::string type;
    if(jsonArray.is_array())
    {
    for(const auto& item:jsonArray)
    {
    type=item["type"];
    jsonObjectCounter++;
    if(type=="Flight")
    {
        if(!isPriceDouble(item["price"].dump()))
        {
           readSuccesful=false;
        }
        if(!(isAirport3Chars(item["fromDest"])))
        {
           readSuccesful=false;
        }
        if(!(isAirport3Chars(item["toDest"])))
        {
           readSuccesful=false;
        }
        FlightBooking inFlightBooking;
        if(item["airline"]!="")
        {
        inFlightBooking.setAirline(item["airline"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["fromDate"]!="")
        {
        inFlightBooking.setFromDate(item["fromDate"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["fromDest"]!="")
        {
        inFlightBooking.setFromDestination(item["fromDest"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["id"]!="")
        {
        inFlightBooking.setID(item["id"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["price"]!="")
        {
        inFlightBooking.setPrice(item["price"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["toDate"]!="")
        {
        inFlightBooking.setToDate(item["toDate"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["toDest"]!="")
        {
        inFlightBooking.setToDestination(item["toDest"]);
        }
        else
        {
            readSuccesful=false;
        }
        inFlightBooking.type=item["type"];
        Bookings.push_back(new FlightBooking(inFlightBooking));
       // cout<<inFlightBooking.showDetails()<<endl;
        flightcounter++;
        flightprice+=double(item["price"]);
        if(!readSuccesful){jsonObjectError=jsonObjectCounter;}

    }
    else if(type=="RentalCar")
    {
        if(!isPriceDouble(item["price"].dump()))
        {
            readSuccesful=false;
        }
        RentalCarReservation inRentalCarReservation;
        if(item["company"]!="")
        {
        inRentalCarReservation.setCompany(item["company"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["fromDate"]!="")
        {
        inRentalCarReservation.setFromDate(item["fromDate"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["id"]!="")
        {
        inRentalCarReservation.setID(item["id"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["pickupLocation"]!="")
        {
        inRentalCarReservation.setPickupLocation(item["pickupLocation"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["price"]!="")
        {
        inRentalCarReservation.setPrice(item["price"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["returnLocation"]!="")
        {
        inRentalCarReservation.setReturnLocation(item["returnLocation"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["toDate"]!="")
        {
        inRentalCarReservation.setToDate(item["toDate"]);
        }
        else
        {
            readSuccesful=false;
        }
        inRentalCarReservation.type=item["type"];
        Bookings.push_back(new RentalCarReservation(inRentalCarReservation));
        carcounter++;
        carprice+=(double)item["price"];
        if(!readSuccesful){jsonObjectError=jsonObjectCounter;}
    }
    else if(type=="Hotel")
    {
        if(!isPriceDouble(item["price"].dump()))
        {
            readSuccesful=false;
        }
        HotelBooking inHotelBooking;
        if(item["fromDate"]!="")
        {
        inHotelBooking.setFromDate(item["fromDate"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["hotel"]!="")
        {
        inHotelBooking.setHotel(item["hotel"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["id"]!="")
        {
        inHotelBooking.setID(item["id"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["price"]!="")
        {
        inHotelBooking.setPrice(item["price"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["toDate"]!="")
        {
        inHotelBooking.setToDate(item["toDate"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["town"]!="")
        {
        inHotelBooking.setTown(item["town"]);
        }
        else
        {
            readSuccesful=false;
        }
        inHotelBooking.type=item["type"];
        Bookings.push_back(new HotelBooking(inHotelBooking));
        cout<<inHotelBooking.showDetails();
        hotelcounter++;
        hotelprice+=(double)item["price"];
        if(!readSuccesful){jsonObjectError=jsonObjectCounter;}
    }
    else if(type=="Train")
    {
        if(!isPriceDouble(item["price"].dump()))
        {
            readSuccesful=false;
        }
        TrainTicket inTrainTicket;
        vector<string>inConnectingStations;
        for(const auto& subitem:item["connectingStations"])
        {
            if(subitem.empty()==false)
            {
                inConnectingStations.push_back(subitem);
            }
            else
            {
                readSuccesful=false;
            }
        }
        if(item["arrivalTime"]!="")
        {
        inTrainTicket.setArrivalTime(item["arrivalTime"]);
        }
        else
        {
            readSuccesful=false;
        }
        inTrainTicket.setConnectingStations(inConnectingStations);
        if(item["departureTime"]!="")
        {
        inTrainTicket.setDepartureTime(item["departureTime"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["fromDate"]!="")
        {
        inTrainTicket.setFromDate(item["fromDate"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["fromStation"]!="")
        {
        inTrainTicket.setFromStation(item["fromStation"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["id"]!="")
        {
        inTrainTicket.setID(item["id"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["price"]!="")
        {
        inTrainTicket.setPrice(item["price"]);
        }
        else
        {
             readSuccesful=false;
        }
        if(item["toDate"]!="")
        {
        inTrainTicket.setToDate(item["toDate"]);
        }
        else
        {
            readSuccesful=false;
        }
        if(item["toStation"]!="")
        {
        inTrainTicket.setToStation(item["toStation"]);
        }
        else
        {
            readSuccesful=false;
        }
        inTrainTicket.type=item["type"];
        Bookings.push_back(new TrainTicket(inTrainTicket));
        traincounter++;
        trainprice+=(double)item["price"];
        if(!readSuccesful){jsonObjectError=jsonObjectCounter;}
    }
    else
    {
        std::cout<<"Ungueltiger Typ!"<<std::endl;
    }
    }
    }
    if(readSuccesful==true){
    errorDetected=false;
    returnmessage="Es wurden insgesamt "+to_string(flightcounter)+" Flüge in Wert von "+to_string(flightprice)+" Euro, "
                    +to_string(traincounter)+" Zugbuchungen in Wert von "+to_string(trainprice)+" Euro, "+to_string(carcounter)+" Mietwagenbuchungen in Wert von "
                    +to_string(carprice)+" Euro, "+to_string(hotelcounter)+" Hotelbuchungen in Wert von "+to_string(hotelprice)+" Euro gefunden.";
    }
    else{
    errorDetected=true;
    returnmessage="Es wurde ein Fehler in Objekt "+to_string(jsonObjectError)+" erkannt, die restlichen Objekte wurden eingelesen!";
    }
}

Booking* TravelAgency::returnBooking(int index){
    return Bookings[index];
}









