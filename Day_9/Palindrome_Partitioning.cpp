#include <bits/stdc++.h> 

bool isPalindrome(int i,int j,string &s)
{
    while(i<=j)
    {
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void fun(int ind,vector<vector<string>>&ans,vector<string>&v,string &s)
{
    if(ind == s.size())
    {
        ans.push_back(v);
        return;
    }
    for(int i=ind;i<s.size();i++)
    {
        if(isPalindrome(ind,i,s) == true)
        {
            v.push_back(s.substr(ind,i-ind+1));
            fun(i+1,ans,v,s);
            v.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>v;
    fun(0,ans,v,s);
    return ans;
}
