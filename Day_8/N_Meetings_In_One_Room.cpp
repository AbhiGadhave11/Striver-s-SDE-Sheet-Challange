#include <bits/stdc++.h> 
static bool comparator(vector<int>&a,vector<int>&b)
{
    if(a[0]<b[0])
        return true;
    if(a[2]<b[2])
    {
        return true;
    }
    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) 
{
    vector<vector<int>>vec;
    int n = start.size();
    for(int i=0;i<n;i++)
    {
        vector<int>v;
        v.push_back(end[i]);
        v.push_back(start[i]);
        
        v.push_back(i+1);
        vec.push_back(v);
    }
    sort(vec.begin(),vec.end(),comparator);

    
    vector<int>ans;
    int limit = vec[0][0];
    ans.push_back(vec[0][2]);
    for(int i=1;i<n;i++)
    {
        if(vec[i][1] > limit)
        {
            limit = vec[i][0];
            ans.push_back(vec[i][2]);
        }
    }
    return ans;
    
}
