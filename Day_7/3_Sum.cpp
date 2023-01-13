#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n) 
{
    vector<vector<int>>ans;
//     int n = arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++)
    {
        if(i == 0 || (i>0 && arr[i]!=arr[i-1]))
        {
            int lo = i+1;
            int hi = n-1;
            int sum = 0 - arr[i];
            while(lo<hi)
            {
                if(arr[lo]+arr[hi] < sum)
                {
                    lo++;
                }
                else if(arr[lo]+arr[hi] > sum)
                {
                    hi--;
                }
                else if(arr[lo]+arr[hi] == sum)
                {
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[lo]);
                    temp.push_back(arr[hi]);
                    ans.push_back(temp);
                    while(lo<hi && arr[lo]==arr[lo+1])
                        lo++;
                    while(lo<hi && arr[hi] == arr[hi-1])
                    {
                        hi--;
                    }
                    lo++;
                    hi--;
                }
            }
        }
    }
	return ans;
}
