// Question #3
// Part(A)

// This function print the character string1 and string2.

#include <iostream>
using namespace std;
void mystery1(char*, const char*); // prototype
int main()
{
	char string1[80];
	char string2[80];
	cout << "Enter two strings: ";
	cin >> string1 >> string2;
	mystery1(string1, string2);
	cout << string1 << endl;
}
void mystery1(char* s1, const char* s2)
{
	while (*s1 != '\0')
	++s1;
	for (; *s1 = *s2; ++s1, ++s2)
	; 
}


Part(B)

This function counts the length of the string1.

#include <iostream>
using namespace std;
int mystery2(const char*); // prototype
int main()
{
	char string1[80];
	cout << "Enter a string: ";
	cin >> string1;
	cout << mystery2(string1) << endl;
} // end main
// What does this function do?
int mystery2(const char* s)
{
	int x;
	for (x = 0; *s != '\0'; ++s)
	++x;
	return x;
}