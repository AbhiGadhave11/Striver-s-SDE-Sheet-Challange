#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &end) 
{
    vector<pair<int,int>>vec;
    for(int i=0;i<start.size();i++)
    {
       
        vec.push_back({end[i],start[i]});
    }
    sort(vec.begin(),vec.end());
    int endtime = vec[0].first;
    int ans = 1;
    for(int i=1;i<start.size();i++)
    {
        if(vec[i].second >= endtime)
        {
            endtime = vec[i].first;
            ans++;
        }
    }
    return ans;
    
}
