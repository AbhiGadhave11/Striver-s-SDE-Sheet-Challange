#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans(n,0);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(st.size()!= 0 && st.top() >= arr[i])
            st.pop();
        if(st.size() != 0)
            ans[i] = st.top();
        else
            ans[i] = -1;
        st.push(arr[i]);
    }
    return ans;
}
