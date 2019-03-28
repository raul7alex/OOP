#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>

class QHBoxLayout;
class QPushButton;
class QLineEdit;

class Dialog : public QMainWindow
{
    Q_OBJECT;
public:
    explicit Dialog(QWidget *parent = 0);
protected slots:
    void on_push_button();

private:
    QHBoxLayout *layout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
};

#endif // DIALOG_H
