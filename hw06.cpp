//附加题 1  奖学金
#include<iostream>
using namespace std;
struct stu
{
	int id;
	int cn;
	int ma;
	int en;
	int to;
};
int main()
{
	int n;
	cin>>n;
	if(n<5)
	{
		cout<<"请输入一个大于等于5，小于等于300的整数";
	}
	else if(n>300)
	{
		cout<<"请输入一个大于等于5，小于等于300的整数";
	}
	else
	{
		stu st[300];
		for(int i=0;i<n;i++)
		{
			st[i].id=i+1;
			cin>>st[i].cn>>st[i].ma>>st[i].en;
			st[i].to=st[i].cn+st[i].ma+st[i].en;
		}
		for(int j=0;j<n-1;j++)
		{
			for(int k=0;k<n-1-j;k++)
			{
				stu temp;
				if(st[k].to<st[k+1].to)
				{
					temp=st[k];
					st[k]=st[k+1];
					st[k+1]=temp;
				}
				else if(st[k].to==st[k+1].to&&st[k].cn<st[k+1].cn)
				{
					temp=st[k];
					st[k]=st[k+1];
					st[k+1]=temp;
				}
				else if(st[k].to=st[k+1].to&&st[k].cn==st[k+1].cn&&st[k].id>st[k+1].id)
				{
					temp=st[k];
					st[k]=st[k+1];
					st[k+1]=temp;
				}
			}
		}
		for(int l=0;l<5;l++)
		{
			cout<<st[l].id<<" "<<st[l].to<<endl;
		}
	}
	return 0;
}