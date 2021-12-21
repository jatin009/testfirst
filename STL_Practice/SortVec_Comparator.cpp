#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Address
{
	int houseno;
	std::string name;

	Address(int h, const std::string& n)
		: houseno(h), name(n) {}
	Address(int h) : houseno(h), name("") {}

	operator std::string() const
	{
		return name + " @ " + std::to_string(houseno);
	}
};

struct AddrComp
{
	bool operator()(const Address& addr1, const Address& addr2)
	{
		return addr1.houseno < addr2.houseno;
	}
};

typedef std::vector<Address> VectorAddress;

void FillVec(VectorAddress& v)
{
	v.push_back(Address(231, "Subhash"));
	v.push_back(Address(321, "Suresh"));
	v.push_back(Address(112, "Abhinav"));
	v.push_back(Address(189, "Rawate"));
	v.push_back(Address(403, "Mihir"));
	v.push_back(Address(409, "Suresh Chand Chauhan"));
	v.push_back(Address(569, "Kailash"));
}

void PrintVec(const VectorAddress& v)
{
	for (auto itr = v.begin(); itr != v.end(); itr++)
	{
		std::string o = *itr;
		std::cout << o << "\n";
	}
}

int main()
{
	// Setup
	VectorAddress vecs;
	FillVec(vecs);
	std::sort(vecs.begin(), vecs.end(), AddrComp());
	PrintVec(vecs);

	// Lookup
	if (std::binary_search(vecs.begin(), vecs.end(), 540, AddrComp()))		//conversion constructor
		std::cout << "540 present";
	else
		std::cout << "540 not present";
	if (std::binary_search(vecs.begin(), vecs.end(), 409, AddrComp()))
		std::cout << "409 present";
	else 
		std::cout << "409 Not present";

	std::cin.get();
	return 0;
}