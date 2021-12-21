#pragma once

class MyString
{
	MyString(const char* str, std::size_t sz)
		: m_Data(new char[sz])
	{
		std::memcpy(m_Data, str, sz);	// memcpy usage
	}
	void Destroy()
	{
		if (m_Data != nullptr)
		{
			delete[] m_Data;
			m_Data = nullptr;
		}
	}
public:
	MyString(const char* str = "")
		: MyString(str, strlen(str) + 1)
	{}
	
	// delegating call to another ctor,
	// only allowed here, and not inside the body
	MyString(const MyString& other)
		: MyString(other.m_Data)
	{
		std::cout << "Copy\n";
	}
	MyString& operator=(const MyString& rhs)
	{
		//std::cout << "Copy\n";

		if (this == &rhs)
			return *this;
		if (rhs.m_Data != nullptr)
		{
			Destroy();
			std::size_t sz = strlen(rhs.m_Data) + 1;
			m_Data = new char[sz];
			std::memcpy(m_Data, rhs.m_Data, sz);
		}
		return *this;
	}
	MyString& operator+ (const MyString& other)
	{
		if (other.m_Data == nullptr)
			return *this;
		char* newData = new char[strlen(m_Data) + strlen(other.m_Data) + 1];
		strcpy(newData, m_Data);			// strcpy usage
		strcat(newData, other.m_Data);		// strcat usage
		Destroy();
		m_Data = newData;
		return *this;
	}
	MyString& operator+= (const MyString& other)
	{
		return operator+(other);
	}
	~MyString()
	{
		//std::cout << "Destroy\n";
		Destroy();
	}
	friend std::ostream& operator<< (std::ostream& os, const MyString& obj)
	{
		os << obj.m_Data << "\n";
		return os;
	}
private:
	char* m_Data = nullptr;
};
