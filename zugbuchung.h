#ifndef ZUGBUCHUNG_H
#define ZUGBUCHUNG_H

#include <QDialog>
#include "TravelAgency.h"
#include "QDateTime"

namespace Ui {
class zugbuchung;
}

class zugbuchung : public QDialog
{
    Q_OBJECT

public:
    explicit zugbuchung(QWidget *parent = nullptr,Booking* inBooking=nullptr);
    ~zugbuchung();

private:
    Ui::zugbuchung *ui;
    TrainTicket *tt;
    void setFelder();
};

#endif // ZUGBUCHUNG_H
