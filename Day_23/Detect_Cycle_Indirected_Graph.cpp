class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int src,int vis[],vector<int>adj[])
    {
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(q.size()!= 0)
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto &it : adj[node])
            {
                if(!vis[it])
                {
                    q.push({it,node});
                    vis[it] = 1;
                }
                else if(parent != it)
                {
                    return true;
                }
            }
            
            
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        int vis[V] = {0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,vis,adj) == true)
                    return true;
            }
        }
        return false;
        // Code here
    }
};
