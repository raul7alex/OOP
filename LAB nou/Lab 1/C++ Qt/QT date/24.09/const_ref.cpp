#include <iostream>
using namespace std;

struct A {
};

void Foo(A& r)
{
}

void Bar(const A& r)
{
}


int main()
{
	A ob;
	Foo(ob);
	ob = A();
//	Foo(A()); // NO !! (O erferinta non-const nu poate referi un rvalue

	Bar(ob); // OK
	Bar(A()); // OK

} 
