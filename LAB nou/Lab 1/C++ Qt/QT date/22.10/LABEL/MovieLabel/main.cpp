#include <QApplication>
#include <QLabel>
#include <QMovie>
#include <QPixmap>
#include <QBitmap>

int main(int argc, char **argv)
{
      QApplication app(argc, argv);

      QLabel* label = new QLabel();
 //     label-> setWindowFlags(Qt::FramelessWindowHint);
 //     label->setMask(QPixmap(":/gif/clock.gif").mask());
    //   label->resize(QSize(200, 200));
      QMovie *movie = new QMovie(":/gif/clock.gif");
      label->setMovie(movie);
      movie->start();

      label->show();
      return app.exec();

}
