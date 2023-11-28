#include "Booking.h"

string Booking::convertDate(string dateToConvert){
    string reverse;
    reverse[0]=dateToConvert[6];
    reverse[1]=dateToConvert[7];
    reverse=reverse+".";
    reverse[3]=dateToConvert[4];
    reverse[4]=dateToConvert[5];
    reverse=reverse+".";
    reverse[6]=dateToConvert[0];
    reverse[7]=dateToConvert[1];
    reverse[8]=dateToConvert[2];
    reverse[9]=dateToConvert[3];
    return reverse;
}
