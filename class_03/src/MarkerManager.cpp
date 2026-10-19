#include "MarkerManager.hpp"
#include<vector>
#include<algorithm>
#include<iostream>

bool MarkerManager::add(const Marker& marker)
{
        if(marker.id<=0 || marker.priority<0 || marker.priority>100)
        {
            return false;
        }
        if(contains(marker.id))
        {
            return false;
        }
        markers_.push_back(marker);
        return true;
};
bool MarkerManager::contains(int id) const
{
        for(const Marker& m : markers_)
        {
            if(id=m.id)
            {
                return true;
            }
        }
        return false;
};
int MarkerManager::count(int yuzhi)
{
        int a=0;
        for(const Marker& ma : markers_)
        {
            if(ma.priority >= yuzhi)
            {
                a++;
            }
        }
        return a;
};
void MarkerManager::printAll()
{
        if(markers_.empty())
        {
            std::cout<<"暂无标记记录";
            return;
        }
        for(const Marker& b : markers_)
        {
            std::cout<<"编号:"<<b.id
                 <<",位置("<<b.x_mm<<", "<<b.y_mm<<")"
                 <<",优先级"<<b.priority<<std::endl;
        }
};
    //PLUS 1
bool MarkerManager::change(int idd,int changep)
{
        if(changep < 0 || changep >100)
        {
            return false;
        }
        if(markers_.empty())
        {
            return false;
        }
        for(Marker m : markers_)
        {
            if(m.id = idd)
            {
                m.priority = changep;
                return true;
            }
        }
};
void MarkerManager::paixu()
{
    std::sort(markers_.begin(),markers_.end(),[](const Marker& a,const Marker& b)
    {
        if(a.priority != b.priority)
        {
            return a.priority > b.priority;
        }
        return a.id > b.id;
    });
};
