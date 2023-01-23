#include<bits/stdc++.h>
void fun(int ind,vector<vector<int>>&ans,vector<int>&v,vector<int>&arr,int target,int n)
{
	if(target == 0)
	{
		ans.push_back(v);
		return;
	}

	for(int i=ind;i<n;i++)
	{
		if(i>ind && arr[i] == arr[i-1])
			continue;
		if(target < arr[i])
			break;
		v.push_back(arr[i]);
		fun(i+1,ans,v,arr,target-arr[i],n);
		v.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	vector<vector<int>>ans;
	vector<int>v;
	sort(arr.begin(),arr.end());
	fun(0,ans,v,arr,target,n);
  
	return ans;
}
