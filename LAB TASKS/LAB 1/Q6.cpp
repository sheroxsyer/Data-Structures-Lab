#include <iostream>
using namespace std;


int Sort(int* a, int size)
{
	int n;
	for (int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(a[j] > a[j+1])
			{
				n = a[j];
				a[j] = a[j+1];
				a[j+1] = n;
			}
		}	
	}	
}
	
int main()
{
	int a[10] = {6,8,25,9,65,3,57,12,4};
	Sort(a, 10);
	return 0;
}


