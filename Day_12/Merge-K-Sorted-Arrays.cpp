#include <bits/stdc++.h> 
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>>&Arr, int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++)
    {
        for(auto &it : Arr[i])
        {
            pq.push(it);
        }
    } 
    vector<int>ans;
    while(pq.size() != 0)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
