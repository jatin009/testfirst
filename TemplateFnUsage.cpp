#include <iostream>

template <class T>
class MyClass {
	T a, b;
	public:
		MyClass(T x, T y):a(x), b(y){}
		T firstNum(){ return a; }
		T secondNum(){ return b; }
		T addNums();
};

template <class T>
T MyClass<T>::addNums ()
{
	return a+b;
}

int main(int argc, char** argv)
{
	std::cout << "Fine" << std::endl;

	MyClass<int> objInt(5, 2);
	std::cout << objInt.addNums() << std::endl;

	MyClass<double> objDouble(5.43, 2.12);
	std::cout << objDouble.addNums() << std::endl;
}
