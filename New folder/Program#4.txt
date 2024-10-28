#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a = 5, b = 10;
	int c;
	int* p1, * p2;
	p1 = &a;
	p2 = &b;
	c = *p1;
	cout << "*(p1++) =" << *(p1++) << endl;   // It is postfix pointer first the value will be assigned and then incremented
	cout << "value of p1 " << p1 << endl;	  // Here the address of p1 is printed
	cout << "*(++p1) =" << *(++p1) << endl;	  // It is prefix pointer first the value is incremented and then assigned
	cout << "value of p1 " << p1 << endl;	  // it prints the address of p1
	cout << "(*p1)++ =" << (*p1)++ << endl;	  // It is postfix pointer
	cout << "value of p1 " << p1 << endl;	  // it prints the address of p1
	cout << "++(*p1) =" << ++(*p1) << endl;	  // It prefix pointer 
	cout << "value of p1 " << p1 << endl;	  // it prints the address of p1
	return 0;
}