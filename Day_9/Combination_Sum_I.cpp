#include<bits/stdc++.h>
void fun(int ind,vector<vector<int>>&ans,vector<int>&v,int target,int n,vector<int>arr)
{
    if(ind == n)
    {
        if(target == 0)
        {
            ans.push_back(v);
        }
        return;
    }
    
    v.push_back(arr[ind]);
    fun(ind+1,ans,v,target-arr[ind],n,arr);
    v.pop_back();
    fun(ind+1,ans,v,target,n,arr);

}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>>ans;
    vector<int>v;
    fun(0,ans,v,k,n,arr);
    return ans;
}
