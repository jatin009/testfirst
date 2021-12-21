#include <iostream>
#include "MyString.h"
#include <vector>

template<typename T>
class MyVector
{
private:
	MyVector(std::size_t capacity) :
		m_Data(new T[capacity])
		, m_Capacity(capacity) {}
	void ReAlloc(std::size_t newCapacity)
	{
		T* oldBlock = m_Data;
		m_Data = new T[newCapacity];
		for (std::size_t i = 0; i < m_Size; i++)
		{
			m_Data[i] = oldBlock[i];
		}
		delete[] oldBlock;
		m_Capacity = newCapacity;
		//T* newBlock = new T[newCapacity];
		//for (std::size_t i = 0; i < m_Size; i++)
		//{
		//	newBlock[i] = m_Data[i];
		//}
		//delete[] m_Data;
		//m_Data = newBlock;
		//m_Capacity = newCapacity;
	}
public:
	MyVector()
		: MyVector(2)
	{}
	~MyVector()
	{
		delete[] m_Data;
	}
	const std::size_t Size() const
	{
		return m_Size;
	}
	void PushBack(const T& element)
	{
		if (m_Size >= m_Capacity)
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_Size] = element;
		++m_Size;
	}
	const T& operator[](std::size_t index) const
	{
		if(index < m_Size)
			return m_Data[index];
	}
	void PopBack()
	{
		if (m_Size > 0)
			--m_Size;
	}
private:
	std::size_t m_Capacity = 0;
	std::size_t m_Size = 0;
	T* m_Data = nullptr;
};

template<typename T>
void Print(const MyVector<T>& v)
{
}

template<>
void Print(const MyVector<MyString>& v)
{
	for (std::size_t i = 0; i < v.Size(); i++)
	{
		std::cout << v[i];
	}
}

int main()
{
	// reserve does not call object constructor,
	// whereas giving size at initialization calls

	MyVector<MyString> strVector;
	
	// first creates MyString from "Hi" using conversion constructor
	// then calls assignment on MyString
	strVector.PushBack("Hi");
	strVector.PushBack("Brother");
	strVector.PushBack("What's up");
	strVector.PopBack();
	strVector.PushBack("Hi");
	strVector.PushBack("Brother");
	strVector.PushBack("What's up");
	strVector.PushBack("Hi");
	strVector.PushBack("Brother");
	strVector.PushBack("What's up");
	Print(strVector);
	std::cout << "------------------\n";
	std::cin.get();
	return 0;
}