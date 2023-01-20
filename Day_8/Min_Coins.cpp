#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int arr[] = {1,2,5,10,20,50,100,500,1000};
    int ans = 0;
    for(int i=8;i>=0;i--)
    {
        while(amount >= arr[i])
        {
            amount = amount - arr[i];
            ans++;
        }
    }
    return ans;
}
