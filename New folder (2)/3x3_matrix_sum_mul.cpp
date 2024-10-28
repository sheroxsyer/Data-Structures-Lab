/*Develop a program to create three 3x3 matrices using DMA and populate those two matrices
using pointers now perform addition and multiplication using pointers and store the result into
third matrix and print them also using pointers.*/

#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int Mat1[3][3],Mat2[3][3],Mat3[3][3],i,j,k,sum;
    cout <<"enter values for mat1"<<endl;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        cin>>Mat1[i][j];

    }
    cout<<"enter values for mat2"<<endl;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        cin>>Mat2[i][j];
    }
    cout<<"first values enter by u for mat1"<<endl;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        cout<<Mat1[i][j]<<endl;
    }
    cout<<"second values enter by u for mat2"<<endl;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        cout<<Mat2[i][j]<<endl;
    }
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        sum = 0;
        for (k=0;k<=2;k++)
        sum = sum+Mat1[i][k]*Mat2[k][j];
        Mat3[i][j]=sum;
        
    }
    cout<<"Product of matrices is "<<endl;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        cout<<Mat3[i][j]<<endl;
        
    }

    return 0;
    

}