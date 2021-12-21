#include <iostream>
#include <string.h>

using namespace std;

int main (int argc, char** argv)
{
	char str1[] = "India";
	char str2[] = "Russia123";

	int srclen = strlen(str1);
	int destlen = strlen(str2);
	int len = ( srclen <= destlen ? srclen : destlen );

	std::cout << "@@@ memmove @@@" << std::endl;
	std::cout << "###Before Copy###" << std::endl;
	std::cout << "str1 = "<< str1 << std::endl;
	std::cout << "str2 = "<< str2 << std::endl;

	strncpy(str2, str1, sizeof(str1));

	std::cout << "###After Copy###" << std::endl;
	std::cout << "str1 = "<< str1 << ", length = " << strlen(str1) << ", sizeof = " << sizeof(str1) << std::endl;
	std::cout << "str2 = "<< str2 << ", length = " << strlen(str2) << ", sizeof = " << sizeof(str2) << std::endl;

	int i=0;
	while (str2[i] != '\0' )
	{
		std::cout << str2[i] << std::endl;
		i++;
	}

/*
	//###################################################################################################

	std::cout << "@@@ memcpy @@@" << std::endl;
	std::cout << "###Before Copy###" << std::endl;
	std::cout << "str1 = "<< str1  << ", length = " << strlen(str1) << ", sizeof = " << sizeof(str1)<< std::endl;
	std::cout << "str2 = "<< str2  << ", length = " << strlen(str2) << ", sizeof = " << sizeof(str2)<< std::endl;

	memcpy(str2, str1, sizeof(str1));

	std::cout << "###After Copy###" << std::endl;
	std::cout << "str1 = "<< str1 << ", length = " << strlen(str1) << ", sizeof = " << sizeof(str1) << std::endl;
	std::cout << "str2 = "<< str2 << ", length = " << strlen(str2) << ", sizeof = " << sizeof(str2) << std::endl;

	//###################################################################################################

	std::cout << "@@@ strncpy @@@" << std::endl;
	std::cout << "###Before Copy###" << std::endl;
	std::cout << "str1 = "<< str1 << std::endl;
	std::cout << "str2 = "<< str2 << std::endl;

	strncpy(str2, str1, len);

	std::cout << "###After Copy###" << std::endl;
	std::cout << "str1 = "<< str1 << ", length = " << strlen(str1) << ", sizeof = " << sizeof(str1) << std::endl;
	std::cout << "str2 = "<< str2 << ", length = " << strlen(str2) << ", sizeof = " << sizeof(str2) << std::endl;

	//###################################################################################################

	std::cout << "@@@ strcpy @@@" << std::endl;
	std::cout << "###Before Copy###" << std::endl;
	std::cout << "str1 = "<< str1 << std::endl;
	std::cout << "str2 = "<< str2 << std::endl;

	strcpy(str2, str1);

	std::cout << "###After Copy###" << std::endl;
	std::cout << "str1 = "<< str1 << ", length = " << strlen(str1) << std::endl;
	std::cout << "str2 = "<< str2 << ", length = " << strlen(str2) << std::endl;
*/
}

