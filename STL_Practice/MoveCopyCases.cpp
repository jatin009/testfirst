#include <iostream>

//g++ Source.cpp --std=c++11  -Wall -Wextra -o  Move

void deprecated_copyassign()
{
	class A
	{
		public:
		A(int x):m_x(x){}
		A(const A& rhs):m_x(rhs.m_x){}	// generation of copy assign op - deprecated due to user-defined copy ctor
		private:
		int m_x;
	};
	A a(2);
	A b(3);
	//b = a;	// requests implicitly generated copy assign op - deprecated due to user-defined copy ctor
}

void deprecated_copyctor()
{
	class A
	{
		public:
		A(int x):m_x(x){}
		A& operator=(const A& rhs){ m_x = rhs.m_x; return *this; }	// generation of copy ctor - deprecated due to user-defined copy assign op
		private:
		int m_x;
	};
	A a(2);
	//A b(a);	// requests implicitly generated copy ctor - deprecated due to user-defined copy assign op
}

void move_as_copy()
{
	class A
	{
		public:
		A(int x):m_x(x){}
		A(const A& rhs):m_x(rhs.m_x){}	// no move op generated due to user-defined copy op
		private:
		int m_x;
	};
	A a(2);
	A b(std::move(a));	// move op request (when not supported) converts into copy op (no move op generation due to user-defined copy op)
	A c = std::move(b);
}

void deleted_copyop()
{
	class A
	{
		public:
		A(int x):m_x(x){}
		A(A&& obj):m_x(obj.m_x){}		// copy op deleted due to user-defined move op
		private:
		int m_x;
	};
	A a(2);
	//A b(a);	// requests implicitly generated copy op - deleted due to user-defined move op
}

void deprecated_dueto_dtor()
{
	class A
	{
		public:
		A(int x):m_x(x){}
		~A(){}
		private:
		int m_x;
	};
	A a(2);
	A b(a);
}

int main()
{
	return 0;
}

/*
---------------------------------------------------------------------------------------
								copy op									move op
---------------------------------------------------------------------------------------
user-defined dtor			gen deprecated (unverified)				not generated
user-defined copy op		(other) gen deprecated					not generated
user-defined move op			deleted							(other) not generated
*/