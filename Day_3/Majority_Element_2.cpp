#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int cnt1 = 0,cnt2 = 0;
    int num1 = 0,num2 = 0;
    for(auto &it : arr)
    {
        if(it == num1)
        {
            cnt1++;
        }
        else if(it == num2)
        {
            cnt2++;
        }
        else if(cnt1 == 0)
        {
            num1 = it;
            cnt1 = 1;
        }
        else if(cnt2 == 0)
        {
            num2 = it;
            cnt2 = 1;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int>ans;
    cnt1 = cnt2 = 0;
    for(auto &it : arr)
    {
        if(it == num1)
            cnt1++;
        else if(it == num2)
            cnt2++;
    }
     if(cnt1>(n/3))
     {
         ans.push_back(num1);
     }
    if(cnt2>(n/3))
        ans.push_back(num2);
    return ans;

}
