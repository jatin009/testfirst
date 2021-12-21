#include <iostream>
#include <string>

/*
 * This program dynamically creates an array to store name and marks of the students,
 * sorts the array using selection sort algorithm and prints back the sorted array.
 */

using namespace std;

struct Student_Data {
	string name;
	int marks;
};

void sortMarksWise(int size, Student_Data* dataArr)
{
	//selection sort algorithm
	for (int iter=0; iter < size-1; iter++)
	{
		int maxIdx = iter;
		for (int i=iter+1;i<size;i++)
		{
			if (dataArr[i].marks > dataArr[maxIdx].marks )
				maxIdx = i;
		}
		Student_Data temp = dataArr[iter];
		dataArr[iter] = dataArr[maxIdx];
		dataArr[maxIdx] = temp;
	}
}

int main (int argc, char** argv)
{
	int count = 0;
	cout << "Enter the number of students: " << endl;
	cin >> count;	
	
	Student_Data *arr = new Student_Data[count];

	for (int i=0;i<count; i++)
	{
		cout << "Student " << (i+1) << " name: " << endl;
		cin >> arr[i].name;
		cout << "Student " << (i+1) << " marks (0-100): " << endl;
		cin >> arr[i].marks;
	}

	sortMarksWise(count, arr);
	cout << "Sorted Order" << endl;

	for (int i=0;i<count; i++)
		cout << arr[i].name << " got " << arr[i].marks << " marks." << endl;

	delete[] arr;

	return 0;
}

