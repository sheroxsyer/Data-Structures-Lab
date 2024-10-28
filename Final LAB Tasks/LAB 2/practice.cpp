#include <iostream>
using namespace std;

void findMode(int *array, int size, int large);

int main()
{
	int size;
	int *array;
	int large=0;
	cout<<"Please enter the number of elements you want   to process: ";
	cin>> size;
	
	array = new int[size];
	
	findMode(array,size,large);
	

	for (int count=0; count<size;count++)
	{
		cout<<"Please enter value #"<<(count+1)<<": ";
		cin>> array[count];
	}

	return 0;
}

void findMode(int *array, int size, int large)
{
	int *array2;
	int count;
	int x;
	int mode = 0;
	int highest = 0;

	array2 = new int[large+1];

	for (count = 0; count < large+1; count++)
		array2[count] = 0;

	for (count = 0; count < size; count++)
	{
		x = array[count];
		array2[x]++;
	}

	for (count = 0; count < large+1; count++)
	{
		if (array2[count] > highest)
		{
			highest = array2[count];
			mode = count;
		}
		
	}
	cout << "The mode is: " << mode << endl;
}