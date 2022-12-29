#include <bits/stdc++.h> 

int findMajorityElement(int arr[], int n) 
{
//     unordered_map<int,int>uobj;
//     for(int i=0;i<n;i++)
//     {
//         uobj[arr[i]]++;
//     }
//     for(auto &it : uobj)
//     {
//         if(it.second>(n/2))
//             return it.first;
//     }
//     return -1;
  
  
    // Moore voting Algorithm
    int cnt = 0,ans = -1;
    for(int i=0;i<n;i++)
    {
        if(cnt == 0)
        {
            ans = arr[i];

        }
        if(ans == arr[i])
            cnt++;
        else
            cnt--;
    }

    return ans;
    
	
}
