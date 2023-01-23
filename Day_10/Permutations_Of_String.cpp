#include <bits/stdc++.h> 
void fun(int ind,string &s,vector<string>&ans,int n)
{
    if(ind == n)
    {
        ans.push_back(s);
        return;
    }
    for(int i=ind;i<n;i++)
    {
        swap(s[ind],s[i]);
        fun(ind+1,s,ans,n);
        swap(s[ind],s[i]);
    }
}
vector<string> findPermutations(string &s) 
{
    vector<string>ans;
    int n = s.size();
    fun(0,s,ans,n);
    return ans;
    
}
