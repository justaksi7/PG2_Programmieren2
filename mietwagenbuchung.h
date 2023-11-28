#ifndef MIETWAGENBUCHUNG_H
#define MIETWAGENBUCHUNG_H
#include "TravelAgency.h"
#include <QDialog>

namespace Ui {
class mietwagenbuchung;
}

class mietwagenbuchung : public QDialog
{
    Q_OBJECT

public:
    explicit mietwagenbuchung(QWidget *parent = nullptr,Booking* inBooking=nullptr);
    ~mietwagenbuchung();

private:
    Ui::mietwagenbuchung *ui;
    RentalCarReservation *rentalcar;
    void setFelder();
};

#endif // MIETWAGENBUCHUNG_H
