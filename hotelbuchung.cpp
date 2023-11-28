#include "hotelbuchung.h"
#include "ui_hotelbuchung.h"

hotelbuchung::hotelbuchung(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotelbuchung)
{
    ui->setupUi(this);
}

hotelbuchung::~hotelbuchung()
{
    delete ui;
}
