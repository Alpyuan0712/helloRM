#include "MarkerManager.hpp"
#include <iostream>
#include <vector>
int howmany(const std::vector<Marker>& markers,int xian)
{
    int many=0;
    for(const Marker& m : markers)
    {
        if(m.priority >= xian)
        {
            many++;
        }
    }
    return many;
}
int main()
{
    //BASE 1
    std::vector<Marker> markers{
        {1,100,200,80},
        {2,200,-50,95},
        {3,0,0,60}
    };
    for(const Marker& m : markers)
    {
        std::cout<<"编号:"<<m.id
                 <<",位置("<<m.x_mm<<", "<<m.y_mm<<")"
                 <<",优先级"<<m.priority<<std::endl;
    }
    std::cout<<"优先级不低于80的数量:"<<howmany(markers, 80)<<std::endl;
    Marker* p = &markers[0];
    Marker& q = markers[0];
    std::cout<<"指针读取:"<<p->id;
    std::cout<<"引用读取:"<<q.id;
}