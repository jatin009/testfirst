#include <iostream>
using namespace std;

int m = 45;

int& getIntVal()
{
	int n = 4;
	int& a = m;	
	cout << "a: " << &a << endl;
	return a;
}

int main()
{
	int x = 1;
	int y = 9999;

	int& ptr = getIntVal();
	cout << "a: " << &ptr << endl;

	return 0;
}
