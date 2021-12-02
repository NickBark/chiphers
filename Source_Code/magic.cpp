#include "magic.h"
#include "ui_magic.h"

Magic::Magic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Magic)
{
    ui->setupUi(this);
}

Magic::~Magic()
{
    delete ui;
}

void Magic::on_pushButton_clicked()
{
    DIM = DIM16;
    str_key = "";

    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Text file"), "", tr("Text Files (*.txt)"));

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        str_key += line + " ";
    }

    str_key.simplified();
    list_key = str_key.split(" ");
    list_key.pop_back();

    qDebug()<<list_key.size();

    if(list_key.size() == 16)
        DIM = DIM16;
    else if(list_key.size() == 25)
        DIM = DIM25;


    for(int i=0; i < DIM ; i++){
        QString tmp = "";
        tmp = list_key.at(i);
        mas[i] = tmp.toInt() - 1;
    }
    //Массив смещений для кодирования
    for(int i=0; i < DIM; i++){
        off[i] = mas[i]-i;
    }

}

void Magic::on_pushButton_2_clicked()
{
    QString str_in = ui->lineEdit->text();
    QString str_cod = QString(str_in.size());

    while (str_in.size()%DIM) {
        str_in += " ";
    }

    if(str_in == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НИЧЕГО НЕ ВВЕЛИ");
        return;
    }
    else if(fileName == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НЕ ДОБАВИЛИ МАГИЧЕСКИЙ КВАДРАТ");
        return;
    }

    int j;
    for(int i = 0; i < str_in.size(); i++){
        j=i%DIM;
        str_cod[i] = str_in[i+off[j]];
    }
    qDebug()<<"COD STRING:"<<str_cod;
    ui->textBrowser->setText(str_cod);
}

void Magic::on_pushButton_3_clicked()
{
    QString str_in = ui->lineEdit->text();
    QString str_dec = QString(str_in.size());

    while (str_in.size()%DIM) {
        str_in += " ";
    }

    if(str_in == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НИЧЕГО НЕ ВВЕЛИ");
        return;
    }
    else if(fileName == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НЕ ДОБАВИЛИ МАГИЧЕСКИЙ КВАДРАТ");
        return;
    }

    int j;
    for(int i = 0; i < str_in.size(); i++){
        j=i%DIM;
        str_dec[i+off[j]] = str_in[i];
    }

    ui->textBrowser_2->setText(str_dec);

}
