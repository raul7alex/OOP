#include <iostream>
using namespace std;

template<typename T>
class StackAbstract{
	virtual int size() const = 0;
    virtual  bool empty() const = 0;
    virtual const T& top() const = 0;
    virtual void push(const T& ob) = 0; 
    virtual void pop() = 0; 
};

template<typename T>
class Stiva : public StackAbstract<T>
{
public:
    // Constructor | Initializarea stivei
    Stiva() {
        varf = nullptr; 
        count = 0; 
    }
    ~Stiva(); // Destructor
    int size() const { return count; } 
    bool empty() const { return varf == nullptr; }
    const T& top() const { 
        if(empty()) throw "Eroare! Stiva Vida!";
        return varf->data;
    }
    void push(const T& ob); 
    void pop(); 
private:
    struct Nod 
    {
        T data; 
        Nod * below;
    };
    Nod * varf; 
    int count;
};

template<typename T> void Stiva<T>::push(const T& ob)
{
    if(empty()) 
    {
        varf = new Nod;
        varf->data = ob;
        varf->below = nullptr;
        count = 1;
    }
    else
    {
        Nod * p = new Nod;
        p->data = ob;
        p->below = varf; 
        varf = p; 
        ++count;  
    }
}

template<typename T> void Stiva<T>::pop()
{
    if(empty()) throw "Eroare! Stiva Vida!";
    Nod * q = varf; 
    varf = varf->below; 
    delete q;
    --count; 
}

template<typename T> Stiva<T>::~Stiva()
{
    while(varf != nullptr)
    {
        Nod * q = varf;
        varf = varf->below;
        delete q;
    }
}


int main()
{
    Stiva<int> a;
    a.push(5);
    a.push(6);
    a.push(7);

    while(!a.empty())
    {
        cout<<a.top() <<' ';
        a.pop();
    }
}
