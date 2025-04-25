#include<iostream>
using namespace std;
int LinearSearch(int n,int key,int arr[])
{
	int i;
for(i=0;i<n;i++)
{
	if(key==arr[i])
	{
		return true;
	}
}
	return false;
}
int main()
{
	int n,i,key,res;
	int arr[100];
	cout<<"Enter array length:"<<endl;
	cin>>n;
	cout<<"Enter element:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter key:"<<endl;
	cin>>key;
	
	res=LinearSearch(n,key,arr);
	if(res==false)
	{
	  cout<<"element not found"<<endl;
	}
	else
	{
		cout<<"Element found"<<endl;
	}
}
