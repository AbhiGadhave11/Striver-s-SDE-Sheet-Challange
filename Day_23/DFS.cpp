class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void DFS(int x,vector<int>&v,vector<int>&vis,vector<int>adj[])
    {
        if(vis[x] == 1)
            return;
            
        vis[x] = 1;
        v.push_back(x);
        
        for(auto &i : adj[x])
        {
           
                DFS(i,v,vis,adj);
                
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int>vobj;
        vector<int> vis(V,0);
        DFS(0,vobj,vis,adj);
        return vobj;
        
    }
};
