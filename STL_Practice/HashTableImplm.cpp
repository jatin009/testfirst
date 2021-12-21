#include <iostream>
#include <string>
#include <list>
#include <memory>

struct HashItem
{
	int key;
	std::string value;
	HashItem(int key, const std::string& value)
		: key(key)
		, value (value)
	{}
};

class HashTable
{
public:
	HashTable(std::size_t sz)
	{
		m_Capacity = nextPrime(sz);
		m_Table = new std::list< std::unique_ptr<HashItem> >[m_Capacity];
	}
	~HashTable()
	{
		delete[] m_Table;
	}
	void InsertItem(const int& key, const std::string& value)
	{
		int index = GetIndex(key);
		m_Table[index].push_back(std::make_unique<HashItem>(key, value));
	}
	std::string SearchItem(const int& key)
	{
		int index = GetIndex(key);
		for (const auto& elem : m_Table[index])
			if (elem->key == key)
				return elem->value;
		return "";
	}
	void PrintTable()
	{
		for (int i = 0; i < m_Capacity; i++)
		{
			std::cout << "table[" << i << "]" ;
			for (const auto& elem : m_Table[i])
			{
				std::cout << "-->";
				std::cout << "(" << elem->key << ", ";
				std::cout << elem->value << ") ";
			}
			std::cout << "\n";
		}
	}
private:
	int GetIndex(const int& key)
	{
		return key % m_Capacity;
	}

	bool isPrime(int n)
	{
		if (n <= 1)  return false;
		if (n <= 3)  return true;
		if (n % 2 == 0 || n % 3 == 0) return false;
		for (int i = 5; i*i <= n; i = i + 6)
			if (n%i == 0 || n % (i + 2) == 0)
				return false;
		return true;
	}

	int nextPrime(int N)
	{
		if (N <= 1)
			return 2;
		int prime = N;
		bool found = false;
		while (!found) {
			prime++;
			if (isPrime(prime))
				found = true;
		}
		return prime;
	}

	std::size_t m_Capacity;
	std::list< std::unique_ptr<HashItem> >* m_Table;
};

int main()
{
	HashTable hashTable(4U);
	hashTable.InsertItem(12, "apple");
	hashTable.InsertItem(23, "mango");
	hashTable.InsertItem(20, "banana");
	hashTable.InsertItem(5, "orange");
	hashTable.PrintTable();

	std::cout << "----- Search Item --------\n";
	std::cout << hashTable.SearchItem(20) << "\n";

	std::cin.get();
	return 0;
}