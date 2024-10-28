#include<iostream.h>
using namespace std;
int main()
{
    int num;
    cout<<"Enter total number of students:";
    cin>>num;
    float*ptr;
    ptr = new float[num];
    cout<<"Enter GPA of students :"<<endl;
    for(int i = 0; i<num;i++)
    {
        cout<<"Students"<<i+1<<": ";
        cin>>*(ptr + i);
    }
    cout<<"Displaying GPA of students"<<endl;
    for(int i = 0;i<num,i++)
    { 
        cout<<"Students"<<i+1<<": "<<*(ptr +i)<<endl;

    }
    delete []ptr;
    return 0;
}