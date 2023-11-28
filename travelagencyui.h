#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H

#include <QMainWindow>
#include "TravelAgency.h"
#include "QFileDialog"
#include "QMessageBox"
#include "QListWidget"
#include "flugbuchung.h"
#include "zugbuchung.h"
#include "hotelbookings.h"
#include "mietwagenbuchung.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TravelAgencyUI; }
QT_END_NAMESPACE

class TravelAgencyUI : public QMainWindow
{
    Q_OBJECT

public:
    TravelAgencyUI(TravelAgency* travelagency=nullptr,QWidget *parent = nullptr);
    ~TravelAgencyUI();

private slots:
    void on_actionEinlesen_triggered();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::TravelAgencyUI *ui;
    TravelAgency* inTravelAgency;
};
#endif // TRAVELAGENCYUI_H
