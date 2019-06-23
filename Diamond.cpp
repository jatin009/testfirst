#include <iostream>
#include "getopt.h"
#include "stdlib.h"

using namespace std;

int main(int argc, char** argv)
{
	int width;

	while (1)
	{
	        int c = getopt(argc, argv, "d:");
	        if (c != -1)
		{
			switch(c)
			{
				case 'd': width = atoll(optarg); break;
				default: width = 7; break;
			}
		}
		else break;
	}

	if ( width % 2 == 0 )
	{
		cout << "Enter only odd numbers." << endl;
		_exit(1);
	}

	int initialSpace = width/2;
	int col_i = 0;
	int row_i = 0;

	for (int i=0;i<width*width;i++)
	{
		col_i = i%width;
		row_i = i/width;
		if ( col_i == 0 && row_i >= 1 )
		{
			if ( row_i <= width/2 )
				initialSpace--;
			else
				initialSpace++;
			cout << endl;
		}
		if(col_i < initialSpace)	//spaces before *
		{
			cout << " ";
		}			
		else if ( initialSpace > width-col_i-1)		//spaces after *
		{
			cout << " ";
		}
		else				//* printing
		{
			cout << "*";
		}
		
	}
	cout << endl;

	return 0;

}
