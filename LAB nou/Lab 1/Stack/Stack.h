

template<typename T>
class Stack{
public: 
	virtual void push(const T&)=0;
	virtual T pop()=0;
	virtual T peek()=0;
	virtual bool isempty()=0;
	virtual bool isfull()=0;
	virtual void print()=0;
	
};


