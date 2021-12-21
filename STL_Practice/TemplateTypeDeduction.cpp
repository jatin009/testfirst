#include <iostream>

//############argument function
template<typename T, typename U, typename V>	// primary Foo template
void Foo(T t, U u, V v) { std::cout << t << ", " << u << ", " << v << std::endl; }

template<>										// full specialization
void Foo<int, bool, char>(int t, bool u, char v) {std::cout << t << ", " << u << ", " << v << std::endl;}

template<>										// full specialization with type deduction
void Foo(int t, bool u, long v) { std::cout << t << ", " << u << ", " << v << std::endl; }

//template<typename T>							// partial specialization not allowed
//void Foo<T, char, bool>(T t, bool u, char v) {}

template<typename U, typename V>				// overloading Foo
void Foo(int t, U u, V v) {std::cout << t << ", " << u << ", " << v << std::endl;}

//############no-argument function
template<typename T, typename U, typename V>	// primary Bar template
void Bar() {}

template<>										// full specialization
void Bar<int , bool , char >() {}

//template<>									// full specialization with type deduction - not allowed here as parameter less function, type cannot be deduced
//void Bar() {}

template<typename T, typename U, typename V>	// primary FooBar class template
class FooBar
{};

template<typename U, typename V>				// partial class template specialization
class FooBar<int, U, V>
{};

template<>										// full specialization of class template
class FooBar<int, bool, char>
{};

template<typename T, typename U>				// cannot rely on return data to deduce return type
T X(U x) { return 2.3f; }

template <typename T, typename U, typename V>
struct FunctorT
{
	FunctorT(U u, V v): m_u(u), m_v(v){}
	U m_u;
	V m_v;
};

int main()
{	
	Foo(1, true, 'a');
	Foo(1, false, 2.334);
	
	Bar<int, bool, long>();
	Bar<int, bool, char>();
	
	FooBar<int, char, bool> f();
	FooBar<long, long, bool> g();
	
	X<float>(2);
	
	//FunctorT<int>(2, 3.4f);		// class template type deduction not allowed, allowed from C++ 17
	return 0;
}