#include "travelagencyui.h"
#include "hotelbuchung.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TravelAgency travelagency;
    TravelAgencyUI w(&travelagency);
    w.show();
    return a.exec();
}
