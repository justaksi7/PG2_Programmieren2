#include "travelagencyui.h"
#include "ui_travelagencyui.h"

TravelAgencyUI::TravelAgencyUI(TravelAgency* travelagency, QWidget *parent)
    :QMainWindow(parent),
    inTravelAgency(travelagency),
    ui(new Ui::TravelAgencyUI)
{
    ui->setupUi(this);

}

TravelAgencyUI::~TravelAgencyUI()
{
    delete inTravelAgency;
    delete ui;
}



void TravelAgencyUI::on_actionEinlesen_triggered()
{
    inTravelAgency->readFile(QFileDialog::getOpenFileName());
    QMessageBox msgBox;
    msgBox.setWindowTitle("Fehler");
    msgBox.setDetailedText("asdsadsadas");
    msgBox.setText(QString::fromStdString(inTravelAgency->returnmessage));
    msgBox.setStandardButtons(QMessageBox::Retry|QMessageBox::Discard|QMessageBox::Cancel);

    if(inTravelAgency->errorDetected==true){
        int ret=msgBox.exec();
        if(ret==msgBox.Discard)
        {
            for(const auto& booking:inTravelAgency->Bookings)
            {
                delete booking;
            }
        }
        else if(ret==msgBox.Cancel)
        {
            msgBox.close();
            for(const auto& booking:inTravelAgency->Bookings)
            {
                ui->listWidget->addItem(QString::fromStdString(booking->showDetails()));
            }
        }
        else if(ret==msgBox.Retry)
        {
            TravelAgencyUI::on_actionEinlesen_triggered();
        }
    }
    else{
        QMessageBox::information(this,"Erfolgreich eingelesen!",QString::fromStdString(inTravelAgency->returnmessage));
        for(const auto& booking:inTravelAgency->Bookings)
        {
            ui->listWidget->addItem(QString::fromStdString(booking->showDetails()));
        }
    }
}


void TravelAgencyUI::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int index=ui->listWidget->row(item);
    if(inTravelAgency->returnBooking(index)->type=="Flight")
    {
        flugbuchung flugdetails(this,inTravelAgency->returnBooking(index));
        flugdetails.exec();
    }
    else if(inTravelAgency->returnBooking(index)->type=="Hotel")
    {
        hotelbookings hoteldetails(this,inTravelAgency->returnBooking(index));
        hoteldetails.exec();
    }
    else if(inTravelAgency->returnBooking(index)->type=="RentalCar")
    {
        mietwagenbuchung mietwagendetails(this,inTravelAgency->returnBooking(index));
        mietwagendetails.exec();
    }
    else
    {
        zugbuchung zugbuchungdetails(this,inTravelAgency->returnBooking(index));
        zugbuchungdetails.exec();
    }
}

