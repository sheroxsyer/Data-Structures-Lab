#include<iostream>
using namespace std;
class Box
{
	public:
		Box()
		{
			cout<<"COnstructor called!"<<endl;
		}
		~Box()
		{
			cout<<"Destructor called!"<<endl;
		}
};
int main()
{
	
	Box*myBoxArray = new Box[4];
	delete[] myBoxArray;
	return 0;
}