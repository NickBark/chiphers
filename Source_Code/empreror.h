#ifndef EMPREROR_H
#define EMPREROR_H

#include "dependence_qt.h"

namespace Ui {
class Empreror;
}

class Empreror : public QDialog
{
    Q_OBJECT

public:
    explicit Empreror(QWidget *parent = 0);
    ~Empreror();

    QMap<QString, QString> mapCod;
    QMap<QString, QString> mapDec;

    QString abc;
    QString fileName;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Empreror *ui;
};

#endif // EMPREROR_H
