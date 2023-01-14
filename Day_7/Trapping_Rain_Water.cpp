#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n)
{
    int left = 0,right = n-1,res = 0;
    int maxleft = 0;
    int rightmax = 0;
    while(left<=right)
    {
        if(arr[left] <= arr[right])
        {
            if(maxleft <= arr[left])
            {
                maxleft = arr[left];
            }
            else
                res = res + (maxleft - arr[left]);
            left++;
        }
        else
        {
            if(rightmax <= arr[right])
            {
                rightmax = arr[right];
            }
            else
                res = res + (rightmax - arr[right]);
            right--;
             
        }
       
    }
    return res;
        
}
