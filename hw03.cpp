//基础题 3  一维数组的动态和
#include<iostream>
using namespace std;
int main()
{
    int n=0;
    int sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	for(int j=0;j<n;j++)
	{
		sum+=arr[j];
		cout<<sum<<" ";
	}
	return 0;
}