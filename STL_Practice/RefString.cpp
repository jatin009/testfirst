#include <iostream>
#include <cstring>

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
			delete[] m_Data;
	}
public:
	MyString(const char* str = "")
		: MyString(str, strlen(str) + 1)
	{}
	MyString(const MyString& other)
	{
		if (other.m_Data != nullptr)
		{
			m_Data = other.m_Data;
			++m_RefCount;
		}
		std::cout << "RefCount = " << m_RefCount << "\n";
	}
	MyString& operator=(const MyString& rhs)
	{
		if (this == &rhs)
			return *this;
		if (rhs.m_Data != nullptr)
		{
			m_Data = rhs.m_Data;
			++m_RefCount;
		}
		std::cout << "RefCount = " << m_RefCount << "\n";
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
		--m_RefCount;
		std::cout << "RefCount = " << m_RefCount << "\n";
		if (m_RefCount == 0)
			Destroy();
	}
	friend std::ostream& operator<< (std::ostream& os, const MyString& obj)
	{
		os << obj.m_Data << "\n";
		return os;
	}
private:
	char* m_Data;
	uint32_t m_RefCount = 1;
};

void print(MyString str)
{
	std::cout << str;
}

int main()
{
	MyString str = "Hi Shobhit Bhai!";		// implicit construction
	print(str);
	std::cin.get();
	return 0;
}