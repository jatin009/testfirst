#include <iostream>
using namespace std;

class A {

public:
	A() { cout << "No-argument constructor." << endl; }
	A(int a=0) { cout << "Default-argument constructor: " << a << endl; }

};

class B {

public:
	B() { foo(); }	
	void foo() { bar(); }
	virtual void bar() { cout << 2 << endl; }
	~B() { foo(); }
};

class C: public B {

public:
	void bar(){ cout << 1 << endl; }	
};

int main()
{
	C c;
	c.foo();
}
