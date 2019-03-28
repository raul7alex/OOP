#include <iostream>
using namespace std;

class QEvent {
public:
	virtual void mousePressButton() = 0;
};


class QMouseEvent : public QEvent {
public:
	virtual void mousePressButton()
	{
		cout << __PRETTY_FUNCTION__ << '\n';
	}
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

	event->mousePressButton(); // OK

	// DownCast
	QMouseEvent *ev = static_cast<QMouseEvent*>(event);
	ev->button();
	
	// DownCast
	QMouseEvent *ev2 = dynamic_cast<QMouseEvent*>(event);
	ev2->x();
}
