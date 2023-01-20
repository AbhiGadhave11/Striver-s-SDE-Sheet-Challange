#include <bits/stdc++.h> 
bool comparator(pair<int,int>&p1,pair<int,int>&p2)
{
    double ans1 = (double)(p1.second)/(double)(p1.first);
    double ans2 = (double)(p2.second)/(double)(p2.first);
    if(ans1 > ans2)
        return true;
    else
        return false;
        
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),comparator);
    double ans = 0.0;
    int totalweight = 0;
    for(auto &it : items)
    {
        if(totalweight+it.first <= w)
        {
            totalweight += it.first;
            ans = ans + it.second;
        }
        else
        {
            int remain = w-totalweight;
            ans +=((it.second)/(double)(it.first))*(double)remain;
        }
    }
    return ans;
}
