
#include<iostream>
using namespace std;

 void table(int x,int lim)

     {
         int a=1;
         do {
        	
        	 cout<<x<<" *" <<a <<"=" <<x *a;
        	x++;
        	
        }
        while(x<lim);
    

     }
 int main()
 {
     int *p,x,*q,lim;
     *p=x;
     *q =lim;
     
     
     cout<<"Enter table Number : "<<endl;
     cin>>*p;
     cout<<"Enter table Limit : "<<endl;
     cin>>*q;

     table(*p,*q);
     
        



	}






