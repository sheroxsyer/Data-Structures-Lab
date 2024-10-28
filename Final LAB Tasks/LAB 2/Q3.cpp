#include <iostream>
using namespace std;
//function used to find section with in start and stop index
void FindSection(char* c, int StartIndex, int StopIndex) 
{
    //we use variable here length
    int length = StopIndex - StartIndex + 1;
    char* string = new char[length + 1];
    
    
    for (int i = 0; i < length; i++) 
    {
        string[i] = c[StartIndex + i];
    }
    string[length] = '\0';
    
   cout << string <<endl;
    
 
}
int main() 
{
    
    char c[] = "My Name is Ali";
    int StartIndex = 3;
    int StopIndex = 6;
    
    FindSection(c, StartIndex, StopIndex);
    
    return 0;
}