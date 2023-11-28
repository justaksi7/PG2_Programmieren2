QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Booking.cpp \
    FlightBooking.cpp \
    HotelBooking.cpp \
    RentalCarReservation.cpp \
    TrainTicket.cpp \
    TravelAgency.cpp \
    flugbuchung.cpp \
    hotelbookings.cpp \
    main.cpp \
    mietwagenbuchung.cpp \
    travelagencyui.cpp \
    zugbuchung.cpp

HEADERS += \
    Booking.h \
    FlightBooking.h \
    HotelBooking.h \
    RentalCarReservation.h \
    TrainTicket.h \
    TravelAgency.h \
    flugbuchung.h \
    hotelbookings.h \
    mietwagenbuchung.h \
    travelagencyui.h \
    zugbuchung.h

FORMS += \
    flugbuchung.ui \
    hotelbookings.ui \
    mietwagenbuchung.ui \
    travelagencyui.ui \
    zugbuchung.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc

DISTFILES += \
    Praktikum2.pro.user \
    download.png
