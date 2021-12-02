#ifndef WINSTON_H
#define WINSTON_H

#include "dependence_qt.h"

namespace Ui {
class Winston;
}

class Winston : public QDialog
{
    Q_OBJECT

public:
    explicit Winston(QWidget *parent = 0);
    ~Winston();

    void ReadKeyFile();

    QString fileName;

    QString Coder_bigram(QString str);
    QString Decoder_bigram(QString str);

    int get_i(QString key[7][5], QString str);
    int get_j(QString key[7][5], QString str);

    QString key_left[7][5];
    QString key_right[7][5];

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Winston *ui;
};

#endif // WINSTON_H
