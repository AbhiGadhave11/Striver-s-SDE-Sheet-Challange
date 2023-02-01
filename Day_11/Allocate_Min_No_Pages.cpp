#include <bits/stdc++.h>
bool isAllocation(long long barrier,vector<int>&time,int k)
{
	long long allostu = 1,pages = 0;
	for(int i=0;i<time.size();i++)
	{
		if(time[i] > barrier)
			return false;
		if(pages+time[i] > barrier)
		{
			allostu++;
		}
		pages = pages + time[i];
	}
	if(allostu > k)
		return false;
	return true;
} 
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long sum = 0;
	int mini= INT_MAX;
	for(auto &it : time)
	{
		sum = sum + it;
		mini = min(mini,it);
	}
	long long low = mini,high = sum,res = 0;
	while(low<=high)
	{
		long long mid = (low + high)/2;
		if(isAllocation(mid,time,m) == true)
		{
			high = mid - 1;
			res = mid;
		}
		else
			low = mid + 1;

	}
	return res;
}
