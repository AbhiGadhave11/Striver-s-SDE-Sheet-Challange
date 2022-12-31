#include <bits/stdc++.h> 

string fourSum(vector<int> arr, int target, int n) 
{
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int left = j+1;
            int right = n-1;
            int tar = target-(arr[i]+arr[j]);
            while(left<=right)
            {
                int two_sum = arr[left]+arr[right];
                if(tar>two_sum)
                {
                    left++;
                }
                else if(tar < two_sum)
                    right--;
                else{
                    return "Yes";
                }
               
            }
             while(j+1<n && arr[j+1] == arr[j])
                    j++;
            
        }
        while(i+1<n && arr[i+1] == arr[i])
                i++;
    }
    return "No";
 
}
