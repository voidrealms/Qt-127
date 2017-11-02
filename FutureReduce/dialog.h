#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtConcurrent>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    static bool doFilter(QString name);

    static void doReduce(QString &result,const QString item);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
