#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::doFilter(QString name)
{
    if(name.toLower() == "bob") return false;
    return true;
}

void Dialog::doReduce(QString &result, const QString item)
{
    result += item + ",";
}

void Dialog::on_pushButton_clicked()
{
    QStringList people;
    people << "Heather" << "Bob" << "Mark" << "Natalie";

    ui->listWidget->clear();
    ui->listWidget->addItems(people);

    QFuture<QString> reduced = QtConcurrent::filteredReduced(people,&Dialog::doFilter, &Dialog::doReduce);
    reduced.waitForFinished();

    QString result = reduced.result();
    result.chop(1);

    ui->lineEdit->setText(result);
}
