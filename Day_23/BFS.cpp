class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    vector<int>BFS(vector<int> adj[],int V)
    {
        queue<int>q;
        vector<int>ans;
        vector<int>vis(V,0);
        q.push(0);
        vis[0] = 1;
        while(q.size() != 0)
        {
            int no = q.front();
            q.pop();
            ans.push_back(no);
            for(auto &it : adj[no])
            {
                if(vis[it] == 0)
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        return BFS(adj,V);
        
    
    }
};
