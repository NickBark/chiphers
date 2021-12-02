#include "winston.h"
#include "ui_winston.h"

Winston::Winston(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Winston)
{
    ui->setupUi(this);
}

Winston::~Winston()
{
    delete ui;
}

void Winston::on_pushButton_3_clicked()
{
    ReadKeyFile();
}

void Winston::ReadKeyFile()
{
    //Диалог открытия файла
    QString str_key;
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Text file"), "", tr("Text Files (*.txt)"));

    //Открываем файл
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    //Читаем файл
    QTextStream in(&file);
    in.setCodec("UTF-8");
    while (!in.atEnd())
    {
        QString line = in.readLine();
        str_key += line;
    }

    QStringList list_key;
    str_key.simplified();
    list_key = str_key.split("<=>", QString::SkipEmptyParts);
   // list_key.pop_back();
    qDebug()<<list_key;
    QString Lkey = list_key[0];
    QString Rkey = list_key[1];
    int k=0;
    for(int i=0; i<7; i++){
        for(int j=0; j<5; j++){
            key_left[i][j]=QString(Lkey[k]);
            key_right[i][j]=QString(Rkey[k]);
            k++;
        }
    }
}

QString Winston::Coder_bigram(QString str)
{
    int i_left = get_i(key_left,QString(str[0]));
    int j_left = get_j(key_left,QString(str[0]));
    int i_right = get_i(key_right,QString(str[1]));
    int j_right = get_j(key_right,QString(str[1]));
//===================================================
    QString out = "";
    if(i_left != i_right){
        out += key_right[i_left][j_right];
        out += key_left[i_right][j_left];
    }else{
        out += key_right[i_right][j_left];
        out += key_left[i_left][j_right];
    }
    return out;
}

QString Winston::Decoder_bigram(QString str)
{
    int i_left = get_i(key_left,QString(str[1]));
    int j_left = get_j(key_left,QString(str[1]));
    int i_right = get_i(key_right,QString(str[0]));
    int j_right = get_j(key_right,QString(str[0]));
//===================================================
    QString out = "";
    if(i_left != i_right){
        out += key_left[i_right][j_left];
        out += key_right[i_left][j_right];
    }else {
        out += key_left[i_left][j_right];
        out += key_right[i_right][j_left];
    }
    return out;
}

int Winston::get_i(QString key[7][5], QString str)
{
    for(int i=0; i<7;i++){
        for(int j=0;j<5;j++){
            if(key[i][j]==str) return i;
        }
    }
    return -1;
}

int Winston::get_j(QString key[7][5], QString str)
{
    for(int i=0; i<7;i++){
        for(int j=0;j<5;j++){
            if(key[i][j]==str) return j;
        }
    }
    return -1;
}


void Winston::on_pushButton_2_clicked()
{
    QString str_in = ui->lineEdit->text();
    QString out = "";

    if(str_in == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НИЧЕГО НЕ ВВЕЛИ");
        return;
    }
    else if(fileName == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НЕ ДОБАВИЛИ ТАБЛИЦЫ");
        return;
    }

    str_in.replace(" ","_");

    qDebug()<<str_in;

    //Добавляем пробел, если длина кодируемой строки нечетная
    if(str_in.size()%2) str_in += "_";

    QString  bigram;
    for(int i=0;i< str_in.size(); i +=2)
    {
        bigram = "";
        bigram += str_in[i];
        bigram += str_in[i+1];
        out += Coder_bigram(bigram);
    }

    ui->textBrowser->setText(out);
}


void Winston::on_pushButton_clicked()
{
    QString str_in = ui->lineEdit->text();
    QString out = "";

    if(str_in == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НИЧЕГО НЕ ВВЕЛИ");
        return;
    }
    else if(fileName == ""){
        QMessageBox::warning(this,"ВНИМАНИЕ","ВЫ НЕ ДОБАВИЛИ ТАБЛИЦЫ");
        return;
    }

    QString  bigram;
    for(int i=0;i< str_in.size(); i +=2)
    {
        bigram = "";
        bigram += str_in[i];
        bigram += str_in[i+1];
        out += Decoder_bigram(bigram);
    }

    out.replace("_"," ");

    ui->textBrowser_2->setText(out);
}
