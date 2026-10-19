#pragma once
#include<vector>
struct Marker
{
    int id;
    double x_mm;
    double y_mm;
    int priority;
};
//BASE 2 and BASE 3
class MarkerManager
{
    public:
    bool add(const Marker& marker);
    bool contains(int id) const;
    int count(int yuzhi);
    void printAll();
    //PLUS 1
    bool change(int idd,int changep);
    void paixu();
    private:
    std::vector<Marker> markers_;
};