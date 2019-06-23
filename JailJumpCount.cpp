#include <iostream>
#include <cstdlib>
#include <vector>
#include <getopt.h>

// To create exe with name, say MyExe (instead of a.out), execute g++ main.cpp -o MyExe
// Note: To execute this program pass arguments like ./JailJumpCount -u up_capacity -d down_slip -n no_of_walls
// OR
// Pass arguments like ./JailJumpCount --up up_capacity --down down_slip --number no_of_walls

using namespace std;

int up = 0;
int down = 0;
int size = 0;

void parse_args(int argc, char** argv)
{
	int option = -1;

	while((option = getopt(argc,argv,"u:d:n:")) != -1)
	{
		switch(option)
		{
			case 'u':
				up = atoi(optarg);
				break;
			case 'd':
				down = atoi(optarg);
				break;
			case 'n':
				size = atoi(optarg);
				break;
			default: break;
		}
	}
}

void parse_args_long (int argc, char** argv)
{
	struct option long_options[] = 
	{
		{"up", required_argument, 0, 'u'},
		{"down", required_argument, 0, 'd'},
		{"number", required_argument, 0, 'n'},
		{0, 0, 0, 0}
	};

	int opt_index = 0;
	int option = -1;
	while ((option = getopt_long(argc,argv,"u:d:n:",long_options,&opt_index)) != -1)
	{				
		switch(option)
		{
			case 'u':
				up = atoi(optarg);
				break;
			case 'd':
				down = atoi(optarg);
				break;
			case 'n':
				size = atoi(optarg);
				break;
			default: break;
		}		
	}
}

int main(int argc, char** argv)
{
//	parse_args(argc,argv);
	parse_args_long(argc,argv);
	cout << "Up: " << up << ", Down: " << down << ", Size: " << size << endl;

	if ( up <= down )
	{
		cout << "Thief won't be able to cross the wall." << endl;
		exit(1);
	}

	vector<int> arr;
	int wall_ht;

	for (int i=0; i < size; i++)
	{		
		cout << "Enter wall " << i+1 << " height: ";
		cin >> wall_ht;
		arr.push_back (wall_ht);
	}

	cout << "Jump capacity: " << up << endl;
	cout << "Down slide: " << down << endl;
	int jumpCount = 0;

	for (int j=0; j<size; j++)
	{
		int heightofwall = arr[j];
		cout << "Height of wall " << j+1 << ": " << heightofwall << endl;;

		while (heightofwall > 0)
		{
			heightofwall -= up;
			jumpCount++;
			if ( heightofwall <= 0 )
				break;
			else heightofwall += down;
		}
	}

	cout << "\nNumber of jumps required to scale all the walls of the jail are: " << jumpCount << endl;

	return 0;
}
