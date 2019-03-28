#include <QApplication>
#include <QPalette>
#include <QFontDialog>
#include <QStyleFactory>
#include <QWidget>


int main(int argc,char ** argv)
{
    QApplication app(argc,argv);
    QFontDialog* dialog = new QFontDialog();
   // qApp->setStyle(QStyleFactory::create("Fusion"));

 //   QPalette* pal = new QPalette();
 //   pal->setColor(QPalette::Window,Qt::red);
    //pal.setColor(QPalette::Background, Qt::red);
 //   QWidget w;
 //   dialog->setPalette(*pal);
  //  w.setStyleSheet("QWidget { background-color: blue; }");
    dialog->exec();//>show();
    return app.exec();
}
