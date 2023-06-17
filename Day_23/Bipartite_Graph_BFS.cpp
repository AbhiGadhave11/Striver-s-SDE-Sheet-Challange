class Solution {
    private:
    bool BFS(int start,vector<int>adj[],vector<int>&color)
    {
        queue<int>q;
        q.push(start);
        color[start] = 0;
        while(q.size() != 0)
        {
            int node = q.front();
            q.pop();
            for(auto &it : adj[node])
            {
                if(color[it] == -1)
                {
                    q.push(it);
                    color[it] = 1-color[node];
                }
                else if(color[it] == color[node])
                {
                    return false;
                }
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
                if(BFS(i,adj,color) == false)
                    return false;
            }
        }
        return true;
        
    }
};
