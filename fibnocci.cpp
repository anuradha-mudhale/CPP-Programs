#include<iostream>
using namespace std;
int main()
{
	int a=0,b=1,c,d;
	cout<<"Enter num"<<endl;
	cin>>d;
	cout<<a<<",";
	cout<<b<<",";
	while(c<=d)
	{
		c=a+b;
		cout<<c<<",";
		a=b;
		b=c;	
	}
	
}
