//基础题 5  小鱼的数字游戏
#include<iostream>
using namespace std;
int main()
{
	int a;
	int i=0;
	int arr[100];
	while(cin>>a)
	{
		if(a==0)
		{
			break; 
		}
		arr[i]=a;
		i++;
	}
	for(int j=i;j>=0;j--)
	{
		if(arr[j]!=0)
		{
			cout<<arr[j]<<" "; 
		}
	}
	return 0;
}