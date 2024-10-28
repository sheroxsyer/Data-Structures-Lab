#include<iostream>
using namespace std;
int main( )
{
           int M1 [3][3], M2[3][3],M3[3][3], i ,j, k, sum; 
           cout<<"Enter values for 1st matrix: "<<endl;
           for ( i = 0 ; i <= 2 ; i++ )
                {
                   for (j = 0 ; j <= 2 ; j++ )
                        cin>>M1 [i][j] ;
                }
                        cout<<" Enter values for 2nd matrix: ";
                   for ( i = 0 ; i <= 2 ; i++ )
                        {
                            for ( j = 0 ; j <= 2 ; j++ )
                                   cin>>M2[i][j] ;
                        }
                       cout<<" The 1st matrix  is:  ";
                            for ( i = 0 ; i <= 2 ; i++ )
                                 {
                                       for ( j = 0 ; j <= 2 ; j++ )
                                              cout<<" "<< M1[i][j] ;
                                              cout<<" ";
                                 }
                                              cout<<" the 2nd matrix is: ";
                                       for ( i = 0 ; i <= 2 ; i++ )
                                            {
                                                for ( j = 0 ; j <= 2 ; j++ )
                                                       cout<<" "<< M2[i][j] ;
                                                       cout<<" ";
                                            }
                                       for ( i = 0 ; i <= 2 ; i++ )
                                            {
                                                for ( j = 0 ; j <= 2 ; j++ )
                                                      {
                                                          sum = 0;
                                                            for ( k = 0 ; k <=2 ; k++ )
                                                                   sum = sum + M1 [i][k] * M2[k][j];
                                                                   M3[i][j] = sum ;
                                                       }
                                             }
                                                                   cout<<" The product of the above two matrices is: ";
                                                                   for ( i = 0 ;i<= 2 ; i++ )
                                                                        {
                                                                             for ( j = 0 ; j <= 2 ; j++ )
                                                                                      cout<<" "<<M3[i][j] ;
                                                                                      cout<<" ";
                                                                         }
                                                                                      cout<<" Press any key to exit.";
                                                                                      return 0;
}