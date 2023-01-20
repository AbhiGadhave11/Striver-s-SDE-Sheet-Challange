#include <bits/stdc++.h> 

void fun(int ind,vector<int>&num,vector<int>&ans,int sum)
{
    if(ind == num.size())
    {
        ans.push_back(sum);
        return;
    }
    fun(ind+1,num,ans,sum+num[ind]);
    fun(ind+1,num,ans,sum);
}
vector<int> subsetSum(vector<int> &num)
{
    int sum = 0;
    vector<int>ans;
    
    fun(0,num,ans,sum);
    sort(ans.begin(),ans.end());
    return ans;
}
