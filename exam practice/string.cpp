
#include<iostream>
using namespace std;
 void print(char*);
 int main()
 {
     cout<<"Enter Table Number : "<<endl;
     


     char str[] = "Enter";
     print(str);

 }
 void print(char *character)
 {
     while(*character != '\0')
     {
     cout<<*character<<endl;
     *character++;
     }
     

 }