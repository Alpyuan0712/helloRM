//基础题 2  闰年判断
#include<iostream>
using namespace std;
int main()
{
    int a;
    bool b;
    cin>>a;
    if(a%4==0 && a%100!=0)
    {
        b=true;
    }
    else if(a%400==0)
    {
        b=true;
    }
    else
    {
        b=false;
    }
    cout<<b;
    return 0;
}