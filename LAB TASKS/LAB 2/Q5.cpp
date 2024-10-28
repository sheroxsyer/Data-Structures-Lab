#include<iostream>
using namespace std;
int main()
{
	char alpha='Y';
	
	const char *p1;
	p1=&alpha;
	*p1='Z';
	cout<<alpha<<endl;
	(We cannot change the value pointed by the p1 because it is 
	 a pointer to constant character)


	char * const p2;
	p2=&alpha;
	char bravo='M';
	p2=&bravo;
	cout<<bravo<<endl;
	(You cannot change the pointer p2 but can change the 
	 value pointed by p)

	
	const char * const p3;
	p3=&alpha;
	char bravo='M';
	p3=&bravo;
	cout<<bravo<<endl;
	cout<<*p3='A';
	(We can neither change the value pointed by the p3 nor the
	 pointer p3 because it is a constant pointer to constant character)
	
	return 0;
}