#include "mietwagenbuchung.h"
#include "ui_mietwagenbuchung.h"

mietwagenbuchung::mietwagenbuchung(QWidget *parent,Booking* inBooking) :
    QDialog(parent),rentalcar(new RentalCarReservation(*dynamic_cast<RentalCarReservation*>(inBooking))),
    ui(new Ui::mietwagenbuchung)
{
    ui->setupUi(this);
    this->setFelder();
}

mietwagenbuchung::~mietwagenbuchung()
{
    delete rentalcar;
    delete ui;
}

void mietwagenbuchung::setFelder()
{
    ui->lineEditID->setText(QString::fromStdString(rentalcar->getID()));
    ui->lineEditCompany->setText(QString::fromStdString(rentalcar->getCompany()));
    ui->lineEditPickupLocation->setText(QString::fromStdString(rentalcar->getPickupLocation()));
    ui->lineEditReturnLocation->setText(QString::fromStdString(rentalcar->getReturnLocation()));
    ui->lineEditPrice->setText(QString::fromStdString(to_string(rentalcar->getPrice())));
    ui->dateEditFromDate->setDate(QDate::fromString(QString::fromStdString(rentalcar->getFromDate()),"yyyyMMdd"));
    ui->dateEditToDate->setDate(QDate::fromString(QString::fromStdString(rentalcar->getToDate()),"yyyyMMdd"));
}
