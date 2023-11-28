#include "hotelbookings.h"
#include "ui_hotelbookings.h"

hotelbookings::hotelbookings(QWidget *parent,Booking* inBooking) :
    QDialog(parent),inhotel(new HotelBooking(*dynamic_cast<HotelBooking*>(inBooking))),
    ui(new Ui::hotelbookings)
{
    ui->setupUi(this);
    this->setFelder();
}

hotelbookings::~hotelbookings()
{
    delete inhotel;
    delete ui;
}

void hotelbookings::setFelder()
{
    ui->dateEditFromDate->setDate(QDate::fromString(QString::fromStdString(inhotel->getFromDate()),"yyyyMMdd"));
    ui->dateEditToDate->setDate(QDate::fromString(QString::fromStdString(inhotel->getToDate()),"yyyyMMdd"));
    ui->lineEditHotel->setText(QString::fromStdString(inhotel->getHotel()));
    ui->lineEditID->setText(QString::fromStdString(inhotel->getID()));
    ui->lineEditTown->setText(QString::fromStdString(inhotel->getTown()));
    ui->lineEditPrice->setText(QString::fromStdString(to_string(inhotel->getPrice())));
}
