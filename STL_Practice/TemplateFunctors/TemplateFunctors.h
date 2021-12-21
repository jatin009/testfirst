#pragma once

struct Student
{
	Student(int marks, int age)
		: m_marks(marks)
		, m_age(age) {}

	bool operator<(const Student& other) const
	{
		return m_marks < other.m_marks;
	}

	bool operator==(int marks) const
	{
		return m_marks == marks;
	}

	int m_marks;
	int m_age;
};

struct StudentsByAgeFunctor
{
	bool operator() (const Student& lhs, const Student& rhs) const
	{
		return lhs.m_age < rhs.m_age;
	}
};

struct FindByAgeFunctor
{
	FindByAgeFunctor(int age)
		: m_age(age) {}
	bool operator() (const Student& other) const
	{
		return m_age == other.m_age;
	}
	int m_age;
};

typedef std::pair<int, bool> IntBoolPair;
typedef std::pair<bool, float> BoolFloatPair;

template<typename T>
struct MatchFirstFunctor
{
	MatchFirstFunctor(T x) : m_x(x) {}

	template<typename U>
	bool operator() (const U& pair)
	{
		return m_x == pair.first;
	}
	T m_x;
};