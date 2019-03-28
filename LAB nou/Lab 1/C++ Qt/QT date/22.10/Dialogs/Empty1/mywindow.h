#ifndef MYWINDOW_H
#define MYWINDOW_H

// foward declaration
#include <QWidget>
class QWidget;
class QPushButton; /// incomplet types
class QLineEdit;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QTextEdit;

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = 0);

    void InitWidgets();
signals:

public slots:
    void OpenDialog();
private:
    QPushButton* openPushButton;
    QLineEdit* textLineEdit;
    QTextEdit *textEdit1;
    QHBoxLayout* hLay1, *hLay2;
    QVBoxLayout* vLay;
    QLabel* textLabel;

};

#endif // MYWINDOW_H
