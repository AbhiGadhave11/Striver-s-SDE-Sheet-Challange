#include <bits/stdc++.h> 
bool comparator(vector<int>&a,vector<int>&b)
{
    if(b[1] < a[1])
      return true;
    return false;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    int count = 0,profit = 0,maxi = INT_MIN;
    for(auto &it : jobs)
    {
        maxi = max(maxi,it[0]);
    }
    sort(jobs.begin(),jobs.end(),comparator);
    
    vector<int>slot(maxi+1,-1);
    for(int i=0;i<n;i++)
    {
        for(int j = jobs[i][0];j>=0;j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = i;
                count++;
                profit += jobs[i][1];
                break;
            }
        }
    }
    return profit;
}
