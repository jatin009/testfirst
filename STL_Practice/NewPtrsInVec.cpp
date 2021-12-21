#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <iterator>

void* operator new(size_t sz)
{
	//std::cout << "Allocating " << sz << " bytes.\n";
	return malloc(sz);
}

void operator delete(void* memory, size_t sz)
{
	//std::cout << "Freeing " << sz << " bytes.\n";
	free(memory);	
}

class A
{
	public:
	A(int x):m_x(x){}
	private:
	int m_x;
};

struct DeleteObject
{
	template<typename T>
	void operator()(const T* ptr)
	{
		delete ptr;
	}
};

int main()
{
	std::vector<A*> v;
	v.push_back(new A(2));
	v.push_back(new A(3));
	v.push_back(new A(21));
	v.push_back(new A(12));
	v.push_back(new A(5));
	v.push_back(new A(6));	
	for_each(v.begin(), v.end(), DeleteObject());		// for_each usage, also note that new done outside vector has to be freed outside manually too
	
	std::vector<std::string> v2;
	v2.push_back("India");
	v2.push_back("is");
	v2.push_back("mycountry");
	std::copy(v2.begin(), v2.end(), std::ostream_iterator<std::string>(std::cout, "\n"));	// ostream_iterator usage
	return 0;
}