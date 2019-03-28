#include<iostream>
#include "Stack.h"
using namespace std;


template <typename T>
class Array_Stack : public Stack<T>{
	public:
	 // Constructor | Initializarea stivei
    Array_Stack() {
        varf = nullptr; // stiva vida
        count = 0; // zero elemente
        capacity = 0x3f3f3f3f;
    }
    
    
      Array_Stack(int capacity) {
        varf = nullptr; // stiva vida
        count = 0; // zero elemente
        this.capacity = capacity;
    }
    ~Array_Stack(); // Destructor
    int size() const { return count; } // Returneaza numarul elementelor din stiva
    bool isempty()  { return varf == nullptr; } // Este stiva vida?
    const T& top() const { // Returneaza o referinta constanta catre varf
        if(isempty()) throw "Eroare! Stiva Vida!";
        return varf->data;
    }
    bool isfull(){
		return size() >= capacity;
	}
    void push(const T& ob); // Adauga un element
    T peek();
    T pop(); // Elimina elementul din varf
    void print();
    
    
private:
    struct Element // Implementeaza un element de stiva
    {
        T data; // Informatia memorata in elementul stivei
        Element * below; // Elementul anterior / dedesubt
        
       public: T get_data(){
			return data;
		}
    };
    Element * varf; // Varful stivei
    int count;	// Data membra cu care numar elementele stivei
    int capacity;
};
	

template<typename T> void Array_Stack<T>::push(const T& ob)
{
    if(isempty()) // Daca stiva este vida
    {
		if(count+1 > capacity)
			throw "Eroare! Stiva este plina!";
        varf = new Element;
        varf->data = ob;
        varf->below = nullptr; // Este baza! Primul element adaugat
        count = 1;
    }
    else
    {
        Element * p = new Element;
        p->data = ob;
        p->below = varf; // Dedesubt se afla fostul varf
        varf = p; // p devine noul varf
        ++count;  // S-a mai adaugat un element
    }
}

template<typename T> T Array_Stack<T>::pop()
{
    // Daca stiva este vida, genereaza o exceptie
    if(isempty()) throw "Eroare! Stiva Vida!";
    Element * q = varf; // Salvez varful
    T x = peek();
    varf = varf->below; // Elementul anterior devine noul varf
    delete q;
    --count; // S-a mai eliminat un element
    
    return x;
}

template<typename T> T Array_Stack<T>::peek()
{
    // Daca stiva este vida, genereaza o exceptie
    if(isempty()) throw "Eroare! Stiva Vida!";
    return varf->get_data();
}

template<typename T> void Array_Stack<T>::print()
{
    for(Element* p=varf; p ;p=p->below)
		std::cout << p->data << std::endl;
}
template<typename T> Array_Stack<T>::~Array_Stack()
{
    while(varf != nullptr)
    {
        Element * q = varf;
        varf = varf->below;
        delete q;
    }
}



int main()
{
	Array_Stack<int> a;
	a.push(5);
	a.push(6);
	a.push(7);
	
	a.print();

	cout << a.pop();
	cout << a.pop();
	cout << a.pop();
	
}
