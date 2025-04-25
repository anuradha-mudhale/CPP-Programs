#include<iostream>
using namespace std;
int main()
{
	int arr[]={2,4,6,8,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
		cout<<"("<<arr[i]<<","<<arr[j]<<")";	
		}
		cout<<endl;
	}
	return 0;	
}
