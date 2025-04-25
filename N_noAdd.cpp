#include<iostream>
using namespace std;
int sum(int n)
{
	if(n==5)
	{
		return n;
	}
	n=n+1;
}
int main()
{
	int n=0;
	sum(n);
	cout<<sum(n);
}
