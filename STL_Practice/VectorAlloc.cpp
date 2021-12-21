#include <iostream>
#include <vector>

#define SAFE_DELETE(x) if(x != nullptr) { delete x; x = nullptr; }

void* operator new (std::size_t sz)
{
	std::cout << "Allocating: " << sz << "\n";
	return malloc(sz);
}

void operator delete(void* memory, std::size_t sz)
{
	std::cout << "Freeing: " << sz << "\n";
	free(memory);
}

struct Foo
{
	Foo(uint32_t x, uint32_t y)			// Parameterized Constructor
		: m_x(x)
		, m_y(new uint32_t(y)) {}
	Foo(const Foo& other)				// Copy Constructor
	{
		m_x = other.m_x;
		if (other.m_y != nullptr)
			m_y = new uint32_t(*other.m_y);
	}
	Foo(Foo&& other)					// Move Constructor
	{
		m_x = other.m_x;
		if (other.m_y != nullptr)
		{
			m_y = other.m_y;
			other.m_y = nullptr;
		}
	}
	Foo& operator=(const Foo& rhs)		// Assignment Operator
	{
		if (this == &rhs)
			return *this;
		m_x = rhs.m_x;
		SAFE_DELETE(m_y);
		m_y = new uint32_t(*rhs.m_y);
		return *this;
	}
	Foo& operator=(Foo&& rhs)			// Move Assignment Operator
	{
		if (this == &rhs)
			return *this;
		m_x = rhs.m_x;
		if (rhs.m_y != nullptr)
		{		
			SAFE_DELETE(m_y);
			m_y = rhs.m_y;
			rhs.m_y = nullptr;
		}
		return *this;
	}
	~Foo()								// Destructor
	{
		SAFE_DELETE(m_y);
	}
	uint32_t m_x;
	uint32_t *m_y = nullptr;
};

void AnalyzeIntAllocation()
{
	std::vector<uint32_t> v;
	v.push_back(1);
	v.push_back(21);
	v.push_back(12);
	v.push_back(13);
}

void AnalyzeStructAllocation()
{
	std::vector<Foo> v;
	std::size_t sz = sizeof(Foo);
	Foo f = Foo(12, 1);
	v.push_back(f);							// copy ctor called
	//v.push_back(std::move(f));			// move ctor called - xrvalue
	/*
	calling operation on f after std::move is valid but has unspecified behavior
	*/
	v.push_back(Foo(12, 1));				// move ctor called - prvalue
	v.push_back(Foo(34, 2));				// move ctor called - prvalue

	/*
	- vector reallocation runs copy ctor
	- push_back user-defined object makes full copy/assignment of the object
		unless used with std::move or
		used with pure rvalue
	  so, good to define copy ctor - move ctor
	*/
}

int main()
{
	//AnalyzeIntAllocation();
	AnalyzeStructAllocation();
	std::cin.get();
	return 0;
}