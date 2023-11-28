#ifndef HOTELBUCHUNG_H
#define HOTELBUCHUNG_H

#include <QDialog>

namespace Ui {
class hotelbuchung;
}

class hotelbuchung : public QDialog
{
    Q_OBJECT

public:
    explicit hotelbuchung(QWidget *parent = nullptr);
    ~hotelbuchung();

private:
    Ui::hotelbuchung *ui;
};

#endif // HOTELBUCHUNG_H
