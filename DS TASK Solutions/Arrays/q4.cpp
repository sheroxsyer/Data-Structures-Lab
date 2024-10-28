//Develop a program to create three 3x3 matrices using DMA and populate those two 
//matrices using pointers now perform addition and multiplication using pointers and
//store the result into third matrix and print them also using pointers.

#include<iostream>
using namespace std;
// declaring and intializing the number of rows and columns in array
int maxr=3; int maxc=3;

// function declaration
void add(int a[], int b[], int c[]);
void mul(int a[], int b[], int c[]);

int main()
{
    int *m1 ; int *m2 ; int *m3;

    // creating 3 2D arrays at run time
    m1=new int[maxr*maxc]; 
    m2=new int[maxr*maxc];
    m3=new int[maxr*maxc];

    //populating the first 2D array
    cout<<"Enter elements for matrix 1 :"<<endl;
    for (int i = 0; i < maxr; i++) // in one iteration of this loop one row will be filled
    {
        cout << "\nEnter elements for row " << i + 1 << " : ";
        for (int j = 0; j < maxc; j++) // in one iteration of this loop 3 columns will be filled
        {
            int c=i * maxc + j; // calculating the location of the element
            cin >> *(m1+c);
        }
    }  
    
    cout<<endl;

    //populating the second 2D matrix
    cout<<"Enter elements for matrix 2 :"<<endl;
    for (int i = 0; i < maxr; i++)
    {
        cout << "\nEnter elements for row " << i + 1 << " : ";
        for (int j = 0; j < maxc; j++)
        {
            int cc=i * maxc + j;
            cin >> *(m2+cc);
        }
    }    

    // calling the function
    add(m1, m2, m3);
    mul(m1, m2, m3);

    return 0;
}

//this ftn will add the corresponding values of the array
void add(int a[], int b[], int c[])
{
    for (int i = 0; i < maxr; i++)
    {
        for (int j = 0; j < maxc; j++)
        {
           int d=i * maxc + j; // calculating the location
            *(c+d)=*(a+d)+*(b+d); // this statement will add the corresponding values
                                  // and then add it to the new 2D array
        }

    }   
    
    //displaying the new array
    cout<<endl;
    cout<<"After adding the corresponding elements of matrix 1 and matrix 2,";
    cout<<"Matrix 3 is as follows: "<<endl;
    for (int i = 0; i < maxr; i++)
    {
        cout << "Row" << i + 1 << " : ";
        for (int j = 0; j < maxc; j++)
        {
            int x=i * maxc + j; // calculating the location
            cout<<*(c+x)<<" ";
        }

        cout<<endl;
    }    
}

//this ftn will multiply the corresponding values of the array
void mul(int a[], int b[], int c[])
{
   for (int i = 0; i < maxr; i++)
    {
        for (int j = 0; j < maxc; j++)
        {
           int d=i * maxc + j;
            *(c+d)=(*(a+d))*(*(b+d)); // this statement will multiply corresponding values
                                  // and then add it to the new 2D array
        }

    }   
    
    //displaying the new array
    cout<<endl;
    cout<<"After multiplying the corresponding elements of matrix 1 and matrix 2,";
    cout<<"Matrix 3 is as follows: "<<endl;
    for (int i = 0; i < maxr; i++)
    {
        cout << "Row" << i + 1 << " : ";
        for (int j = 0; j < maxc; j++)
        {
            int x=i * maxc + j;
            cout<<*(c+x)<<" ";
        }

        cout<<endl;
    }
}
