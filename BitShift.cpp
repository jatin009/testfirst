#include <iostream>
using namespace std;

int main()
{
	int x = 1;
	int y = 9999;

	std::cout << "Left Shift by 0: " << (x << 0) << std::endl;
	std::cout << "Left Shift by 1: " << (x << 1) << std::endl;

	std::cout << "Right Shift by 1: " << (x >> 1) << std::endl;
	std::cout << "y: " << y << std::endl;
	
	return 0;
}
