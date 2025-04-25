#include<iostream>
using namespace std;
int main()
{
	int i,fact=1,n;
	cout<<"Enter the number:"<<endl;
	cin>>n;
	for(i=n;i>=1;i--)
	{
		fact = fact*i;

	}
	cout<<"factorial is:"<<fact<<endl;
	return 0;
}
