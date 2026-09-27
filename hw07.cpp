//附加题 2  机器人回原点
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int x=0;
	int y=0;
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='U')y++;
		if(a[i]=='D')y--;
		if(a[i]=='L')x--;
		if(a[i]=='R')x++;
	} 
	if(x==0&&y==0)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
	return 0;
}