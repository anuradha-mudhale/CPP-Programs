#include<iostream>
using namespace std;
int main()
{
	int i,n,price[10];
	string item[10];
	int total=0;
	cout<<"Grossary Bill"<<endl;
	cout<<"Enter Total Items You want to Bill"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter item and its price:"<<endl;
		cin>>item[i]>>price[i];
		total = price[i];
	}
	cout<<"Item"<<'\t'<<"price"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<item[i]<<price[i]<<endl;
	}
	cout<<"Total is:"<<total<<endl;
	return 0;
}
