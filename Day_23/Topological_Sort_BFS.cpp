#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    vector<int>adj[v];
    for(auto &it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }
    vector<int>ndegree(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto &it : adj[i])
        {
            ndegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(ndegree[i] == 0)
            q.push(i);
    }
    vector<int>ans;
    while(q.size() != 0)
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto &it : adj[node])
        {
            ndegree[it]--;
            if(ndegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
}
