class Solution {
    private:
    bool dfs(int node,int prevcolor,vector<int>adj[],vector<int>&color)
    {
        color[node] = 1-prevcolor;
        for(auto &it  : adj[node])
        {
            if(color[it] == -1)
            {
                if(dfs(it,color[node],adj,color) == false)
                    return false;
            }
            else if(color[it] == color[node])
            {
                return false;
            }
        }
        return true;
    }
   
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int>color(n,-1);
        vector<int>adj[n];
        int a = 0;
        for(auto &it : graph)
        {
            for(auto &jt : it)
            {
                 
                adj[a].push_back(jt);
                adj[jt].push_back(a);
            }
           a++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i,1,adj,color) == false)
                    return false;
            }
        }
        return true;
        
    }
};
