#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
	vector<vector<int>>ans;
	int n = arr.size();
	unordered_map<int,int>uobj;
	for(int i=0;i<n;i++)
	{
		if(uobj.find(s-arr[i]) != uobj.end()){
			ans.push_back({s-arr[i],i});
		}
		else{
			uobj[arr[i]] = i;
		}
	}
	return ans;
}
