#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<uint32_t>& v)
{
	for(auto elem: v)
		std::cout << elem << ", ";
}

int main()
{	
	std::vector<uint32_t> v = {1,2,3,4,5,6,7,8};
	auto itr = std::find(v.rbegin(), v.rend(), 3);
	std::cout << *itr << "\n";						// Logically reverse_iterator is at 3
	v.erase(itr.base());							// Physicall it's at 4
	print(v);
	
	std::cout << "\n" << v.max_size() << "\n";		// to find max size of STL containers
	
	return 0;
}