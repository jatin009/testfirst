#include <iostream>
#include <vector>
#include <algorithm>
#include "TemplateFunctors.h"
#include "TypeDeduction.h"

void UseTemplateFunctors()
{
	std::vector<Student> v = { Student(67, 12), Student(78, 11), Student(81, 13), Student(95, 10) };
	std::sort(v.begin(), v.end());	// looks for operator<() in contained object's class
	std::find(v.begin(), v.end(), 78);	// looks for operator==() in contained object's class
	std::sort(v.begin(), v.end(), StudentsByAgeFunctor());
	std::find_if(v.begin(), v.end(), FindByAgeFunctor(12));
}

void UsePairFunctors()
{
	std::vector<IntBoolPair> v = { std::make_pair(1, true), std::make_pair(2, false) };
	std::vector<BoolFloatPair> v2 = { std::make_pair( true, 2.f), std::make_pair(false, 3.4f) };
	std::find_if(v.begin(), v.end(), MatchFirstFunctor<int>(2));
	std::find_if(v2.begin(), v2.end(), MatchFirstFunctor<bool>(false));
}

int main()
{
//	UseTemplateFunctors();
	//UsePairFunctors();
	int x = 2;
	f(x);
	f(3);
	std::unique_ptr<int> ptr = std::make_unique<int>(2);
	//int* & ptr2 = ptr;
	//int* && ptr3 = new int(3);
	
	f(ptr);

	return 0;
}
