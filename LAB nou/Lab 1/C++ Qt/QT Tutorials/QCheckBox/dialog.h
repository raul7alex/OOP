#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
class QHBoxLayout;
class QCheckBox;
class QPushButton;

class Dialog : public QMainWindow
{
    Q_OBJECT;
public:
    explicit Dialog(QWidget *parent = 0);
protected slots:
    void on_push_button();
private:
    QHBoxLayout *layout;
    QCheckBox *checkBox;
    QPushButton *pushButton;
};

#endif // DIALOG_H
