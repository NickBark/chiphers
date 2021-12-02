#include "empreror.h"
#include "ui_empreror.h"

Empreror::Empreror(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Empreror)
{
    ui->setupUi(this);
}

Empreror::~Empreror()
{
    delete ui;
}

void Empreror::on_pushButton_clicked()
{
    QString str_in = ui->lineEdit->text();
    QString str_cod = "";

    if(str_in == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НИЧЕГО НЕ ВВЕЛИ");
        return;
    }
    else if(fileName == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НЕ ДОБАВИЛИ АЛФАВИТ");
        return;
    }

    int off = ui->spinBox->value();

    mapCod.clear();

    for(int i = 0; i < abc.size() - off; i++)
        mapCod[QString(abc[i])] = abc[i+off];

    int j = 0;
    for(int i = abc.size() - off; i < abc.size(); i++)
        mapCod[QString(abc[i])] = abc[j++];


    for(int i = 0; i<str_in.size();i++)
        str_cod += mapCod[ QString(str_in[i])];

    ui->textBrowser->setText(str_cod);
}

void Empreror::on_pushButton_2_clicked()
{
    QString str_in = ui->lineEdit->text();
    QString str_cod = "";

    if(str_in == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НИЧЕГО НЕ ВВЕЛИ");
        return;
    }
    else if(fileName == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НЕ ДОБАВИЛИ АЛФАВИТ");
        return;
    }

    int off = ui->spinBox->value();

    mapDec.clear();

    for(int i = 0; i < abc.size() - off; i++)
        mapDec[QString(abc[i+off])] = abc[i];

    int j = 0;
    for(int i = abc.size() - off; i < abc.size(); i++)
        mapDec[QString(abc[j++])] = abc[i];

    for(int i = 0; i<str_in.size();i++)
        str_cod += mapDec[ QString(str_in[i])];

    ui->textBrowser_2->setText(str_cod);
}

void Empreror::on_pushButton_3_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Text file"), "", tr("Text Files (*.txt)"));

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;

    QTextStream in(&file);
    in.setCodec("UTF-8");

    while (!in.atEnd())
    {
        QString line = in.readLine();
        abc += line;
    }
    qDebug()<<abc;
}
