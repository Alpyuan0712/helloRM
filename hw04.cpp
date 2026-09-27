//基础题 4  打分
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double arr[5];
	double m=0;
	double n=10;
	for(int i=0;i<5;i++)
	{
		cin>>arr[i];
	}
	for(int j=0;j<5;j++)
	{
		if(m<arr[j])
		{
			m=arr[j];
		}
		if(n>arr[j])
		{
			n=arr[j];
		}
	}
	printf("%.2f",(arr[0]+arr[1]+arr[2]+arr[3]+arr[4]-m-n)/3) ;
	return 0;
}