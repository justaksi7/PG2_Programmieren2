#ifndef HOTELBUCHUNG_H
#define HOTELBUCHUNG_H
#include "TravelAgency.h"
#include <QDialog>

namespace Ui {
class flugbuchung;
}

class flugbuchung : public QDialog
{
    Q_OBJECT

public:
    explicit flugbuchung(QWidget *parent = nullptr,Booking* inBooking=nullptr);
    ~flugbuchung();

private:
    Ui::flugbuchung *ui;
    FlightBooking *flight;
    void setFelder();
};

#endif // HOTELBUCHUNG_H
