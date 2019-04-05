#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <QMessageBox>
#include "tpnumber.h"
#include "tanumber.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_19, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_20, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_65, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_66, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_67, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_68, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_69, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_70, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_97, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_98, SIGNAL(clicked()), this, SLOT (Calculated()));
    connect(ui->pushButton_99, SIGNAL(clicked()), this, SLOT (Calculated()));
    ui->comboBox->setEnabled(false);
    ui->pushButton_65->setEnabled(false);
    ui->pushButton_66->setEnabled(false);
    ui->pushButton_67->setEnabled(false);
    ui->pushButton_68->setEnabled(false);
    ui->pushButton_69->setEnabled(false);
    ui->pushButton_70->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Calculated(){
    QString temp = qobject_cast<QPushButton*>(sender())->objectName();
    QString name = qobject_cast<QPushButton*>(sender())->text();
    //QMessageBox::information(this, "внимание", temp);
    temp = temp.mid(11, temp.length());
    int command =0;
    qDebug() << temp.toInt();
    if(temp.toInt() <= 10 && temp.toInt() >= 1) command = 110 + temp.toInt();
    else if(temp.toInt() <= 70 && temp.toInt() >= 65) command = 120 + temp.toInt()-64;
    else if(temp.toInt() == 11) command = 101;
    else if(temp.toInt() == 19) command = 102;
    else if(temp.toInt() == 20) command = 103;
    else if(temp.toInt() == 12) command = 7;
    else if(temp.toInt() > 96) command = -17 + temp.toInt();
    else if(temp.toInt() >= 13) command = temp.toInt() - 12;
    this->calc.runCalc(command);
    ui->lineEdit->setText(this->calc.editor->chislo);  
    ui->lineEdit_2->setText(this->calc.NumToStr(calc.type, *this->calc.memory.FNumber));
    //QMessageBox::information(this, "внимание", this->calc.editor->chislo);
}

void MainWindow::on_radioButton_clicked()
{
    ui->comboBox->setEnabled(false);
    ui->pushButton_65->setEnabled(false);
    ui->pushButton_66->setEnabled(false);
    ui->pushButton_67->setEnabled(false);
    ui->pushButton_68->setEnabled(false);
    ui->pushButton_69->setEnabled(false);
    ui->pushButton_70->setEnabled(false);
    this->calc = TCtrl(Frac);
    this->calc.type = Frac;
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->comboBox->setEnabled(false);
    ui->pushButton_65->setEnabled(false);
    ui->pushButton_66->setEnabled(false);
    ui->pushButton_67->setEnabled(false);
    ui->pushButton_68->setEnabled(false);
    ui->pushButton_69->setEnabled(false);
    ui->pushButton_70->setEnabled(false);
    this->calc = TCtrl(Complex);
    this->calc.type = Complex;
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->comboBox->setEnabled(true);
    ui->pushButton_65->setEnabled(true);
    ui->pushButton_66->setEnabled(true);
    ui->pushButton_67->setEnabled(true);
    ui->pushButton_68->setEnabled(true);
    ui->pushButton_69->setEnabled(true);
    ui->pushButton_70->setEnabled(true);
    this->calc = TCtrl(ui->comboBox->currentText().toInt());
    this->calc.type = PNumber;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    this->calc = TCtrl(arg1.toInt());
    this->calc.type = PNumber;
}
