#ifndef HOTELBOOKINGS_H
#define HOTELBOOKINGS_H
#include "TravelAgency.h"
#include <QDialog>

namespace Ui {
class hotelbookings;
}

class hotelbookings : public QDialog
{
    Q_OBJECT

public:
    explicit hotelbookings(QWidget *parent = nullptr,Booking* inBooking=nullptr);
    ~hotelbookings();

private:
    Ui::hotelbookings *ui;
    HotelBooking* inhotel;
    void setFelder();
};

#endif // HOTELBOOKINGS_H
