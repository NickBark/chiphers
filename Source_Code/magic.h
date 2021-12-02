#ifndef MAGIC_H
#define MAGIC_H

#include "dependence_qt.h"
#include "const.h"


namespace Ui {
class Magic;
}

class Magic : public QDialog
{
    Q_OBJECT

public:
    explicit Magic(QWidget *parent = 0);
    ~Magic();

    QString fileName;
    QString str_key;
    QStringList list_key;

    //Максимальная размерность ключа
    int mas[DIM100];
    int decmas[DIM100];
    int off[DIM100];

    int DIM;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Magic *ui;
};

#endif // MAGIC_H
