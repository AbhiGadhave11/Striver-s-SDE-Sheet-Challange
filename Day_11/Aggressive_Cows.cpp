#include <bits/stdc++.h>
bool isCowPlace(int dist,vector<int>&arr,int cows)
{
	int co_ord = arr[0], cnt = 1;
	for(int i=1;i<arr.size();i++)
	{
		if(arr[i]-co_ord >= dist)
		{
			cnt++;
			co_ord = arr[i];
		}
		if(cnt == cows)
			return true;
	}
	return false;
} 
int chessTournament(vector<int> arr , int n ,  int c)
{
	sort(arr.begin(),arr.end());
	int low = 1,high = arr[n]-arr[0];
	int ans = 0;
	while(low<=high)
	{
		int mid = (low + high)/2;
		if(isCowPlace(mid,arr,c))
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return ans;
}
