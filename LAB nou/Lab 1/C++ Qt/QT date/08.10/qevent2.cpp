// DOWNCAST
#include <iostream>
using namespace std;


class QEvent {
public:
	virtual void type() 
	{
		cout << __PRETTY_FUNCTION__ << '\n';
	}
};


class QMouseEvent : public QEvent {
public:
	void type() 
	{
		cout << __PRETTY_FUNCTION__ << '\n';
	}
	
	void button()
	{
		cout << __PRETTY_FUNCTION__ << '\n';
	}
};


void eventFilter(QEvent * event)
{
	event->type();     // Dynamic Binding (POLIMORFISDM)
//	event->button();   // Static Binding
		
	static_cast<QMouseEvent*>(event)->button(); // C-style Type Cast Op.
}


int main()
{
	eventFilter(new QMouseEvent);
}
