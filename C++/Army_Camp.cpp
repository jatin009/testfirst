#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    string str1, input1;
    getline(cin, str1);
    string str2, input2;
    getline(cin, str2);

    //removing spaces from str1
//    for (short unsigned int i=0;i<str1.length();i++)
//    {
//        char c = str1[i];
//        if (c != ' ')
//        {
//            input1 += c;
//        }
//    }

    //removing spaces from str2
//    for (short unsigned int i=0;i<str2.length();i++)
//    {
//        char c = str2[i];
//        if (c != ' ')
//        {
//            input2 += c;
//        }
//    }

    short unsigned int length1 = input1.length();

    if ( length1 != input2.length() )
	{
        cout << "No" << endl;
        _exit(0);
	}

    bool ordermatch = false;

    char a = input2[0];
    short int firstIdx = str1.find(a);
//    short int lastIdx = str1.rfind(a);

    if ( firstIdx == -1 )
    {
        cout << "No" << endl;
        _exit(0);
    }
	std::vector<int> v;

	int i=0;
	while(i != length1)
	{
        if ( input1[i] == a )
			v.push_back(i);		
		i++;
	}

//    if ( v.size() == 0 )
//    {
//        cout << "No" << endl;
//        _exit(0);
//    }

    for (short unsigned int j=0;j<v.size();j++)
	{
		int secondIdx=0;
		int elem = v[j];

        //right traversal
		while(secondIdx != length1)
		{
            if ( input2[secondIdx] != input1[elem] )
			{
				break;
			}
			secondIdx++;
			if ( ++elem == length1 )
				elem = 0;
		}
        if ( secondIdx == length1 )
        {
            ordermatch = true;
			break;
        }

		secondIdx=0;
		elem = v[j];

        //left traversal
		while(secondIdx != length1)
		{
            if ( input2[secondIdx] != input1[elem] )
			{
				break;
			}
			secondIdx++;
			if ( --elem == -1 )
				elem = length1-1;
		}

        if ( secondIdx == length1 )
        {
            ordermatch = true;
			break;
        }
	}

	if (ordermatch)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
