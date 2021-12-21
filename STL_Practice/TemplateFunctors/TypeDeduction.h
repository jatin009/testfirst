#pragma once
#include <iostream>

template<typename T>
void f(T&& val)
{
	std::cout << "Type Id: " << typeid(T).name() << ", Val: " << val << "\n";
}

//template<typename T>
//void f(T& val)
//{
//	std::cout << "Type Id: " << typeid(T).name() << ", Val: " << val << "\n";
//}

//template<typename T>
//void f(T val)
//{
//	std::cout << "Type Id: " << typeid(T).name() << ", Val: " << val << "\n";
//}