#include "flugbuchung.h"
#include "ui_flugbuchung.h"

flugbuchung::flugbuchung(QWidget *parent, Booking *inBooking) :
    QDialog(parent),flight(new FlightBooking(*dynamic_cast<FlightBooking*>(inBooking))),
    ui(new Ui::flugbuchung)
{
    ui->setupUi(this);
    this->setFelder();
}

void flugbuchung::setFelder(){
    ui->airlineLineEdit->setText(QString::fromStdString(flight->getAirline()));
    ui->fromDateEdit->setDate(QDate::fromString(QString::fromStdString(flight->getFromDate()),"yyyyMMdd"));
    ui->fromDestLineEdit->setText(QString::fromStdString(flight->getFromDestination()));
    ui->toDateEdit->setDate(QDate::fromString(QString::fromStdString(flight->getToDate()),"yyyyMMdd"));
    ui->IDlineEdit->setText(QString::fromStdString(flight->getID()));
    ui->toDestLineEdit->setText(QString::fromStdString(flight->getToDestination()));
    ui->priceLineEdit->setText(QString::fromStdString(to_string(flight->getPrice())));
}

flugbuchung::~flugbuchung()
{
    delete flight;
    delete ui;
}
