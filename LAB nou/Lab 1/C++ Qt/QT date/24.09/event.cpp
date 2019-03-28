#include <iostream>
using namespace std;

class QEvent {
public:
};


class QMouseEvent : public QEvent {
public:
	void button()
	{
		cout << __PRETTY_FUNCTION__ << '\n';
	}
	
	int x()
	{
		cout << __PRETTY_FUNCTION__ << '\n';
		return 0;
	}
};

int main()
{
	
	QEvent *event = new QMouseEvent();
	
//	event->x(); // NO !!
//	QMouseEvent *ev = (QMouseEvent*)event; // OK dar invechit

	QMouseEvent *ev = static_cast<QMouseEvent*>(event);
	ev->button();
}
