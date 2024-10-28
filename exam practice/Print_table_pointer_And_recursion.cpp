#include<iostream>
using namespace std;
void Table(int *p,int *ptr)
{
    
    int i =1;
    if(i>*ptr)
    {
        return;

    }
    
    
    
    cout<<*p<<"*"<<i<<"="<<*p*i<<endl;
    return Table(p,ptr+1);    

}
int main()
{
    int No;
    int Limit;
    int *p;
    p=&No;

    int *ptr; 
    ptr=&Limit;
    cout<<"Enter table Number:"<<endl;
    cin>>No;
    cout<<"Enter table Limit:"<<endl;
    cin>>Limit;
    Table(p,ptr);
    
    

    return 0;

}