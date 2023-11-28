#include "zugbuchung.h"
#include "ui_zugbuchung.h"

zugbuchung::zugbuchung(QWidget *parent,Booking* inBooking) :
    QDialog(parent),
    tt(new TrainTicket(*dynamic_cast<TrainTicket*>(inBooking))),
    ui(new Ui::zugbuchung)
{
    ui->setupUi(this);
    this->setFelder();
}

void zugbuchung::setFelder()
{
    ui->connectingStextEdit->setText(QString::fromStdString(tt->getConnectingStations()));

    ui->FromdateTimeEdit->setDate(QDate::fromString(QString::fromStdString(tt->getFromDate()),"yyyyMMdd"));
    ui->FromdateTimeEdit->setTime(QTime::fromString(QString::fromStdString(tt->getDepartureTime())));
    ui->TodateTimeEdit->setDate(QDate::fromString(QString::fromStdString(tt->getToDate()),"yyyyMMdd"));
    ui->TodateTimeEdit->setTime(QTime::fromString(QString::fromStdString(tt->getArrivalTime())));
    ui->IDlineEdit->setText(QString::fromStdString(tt->getID()));
    ui->FromlineEdit->setText(QString::fromStdString(tt->getFromStation()));
    ui->TolineEdit->setText(QString::fromStdString(tt->getToStation()));
    ui->PricelineEdit->setText(QString::fromStdString(to_string(tt->getPrice())));
}
zugbuchung::~zugbuchung()
{
    delete tt;
    delete ui;
}
