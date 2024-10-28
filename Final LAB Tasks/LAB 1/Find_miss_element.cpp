#include<iostream>
using namespace std;
int find_small_val(int A[],int size ){

for (int i = 1; i <= size; i++)         //for element check
{
        

    for (int j = 0; j < size; j++)          //whole array element check
    {

        // Handling only negative case here
        if (A[j]<0)             //if value is less then go in
        {            if(i==A[j]){       //if value of i not equal not in usuall this case will not be true and it goes end if condition (after positive check)
            //  it is true when first is negative and other value is positive
            
            if(i==size)
            {        
                return i+1;    
            }
         else if (i!=A[j] && j+1==size)
         {
            return i;
         }else {
         return 1;
        
         }
                            break;
        }       
}
// Here positive case :
              if(i==A[j]){      //if value is equal inside
         if(i==size)            //check the last value
            {   
                return i+1;    
            }
                    break;
         }if (i!=A[j] && j+1==size)         //if value is not inside and and it check the whole array just return that missing value
         {
            return i;
         }
    }
}        
    }

int main(){
    // int A[]={1,3,6,4,1,2};
 int A[] = {2, -1,-3 };
int size=3;
int answer;
answer=find_small_val(A,size);
cout<<"The answer is :"<<answer<<endl;
return 0;
}