

class Solution
{
    private : 
    void dfs(int node,vector<int> adj[],stack<int>&st,vector<int>&vis){
        vis[node] = 1;
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,st,vis);
            }
        }
        st.push(node);
        
    }
    
    void dfs1(int node,vector<int>&vis,vector<int>adjR[]){
        vis[node] = 1;
        for(auto &it : adjR[node]){
            if(!vis[it]){
                dfs1(it,vis,adjR);
            }
        }
      
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int>vis(V,0);
        stack<int>st;
        //sort according to finishing time
        for(int i=0;i<V;i++)
        {
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }
        // reverse the graph
        vector<int>adjR[V];
        for(int i=0;i<V;i++)
        {
            vis[i] = 0;
            for(auto &it : adj[i]){
                adjR[it].push_back(i);
            }
        }
        int ans = 0;
        // explore the stack
        while(st.size()!= 0)
        {
            int node = st.top();
            st.pop();
            if(!vis[node]){
                ans++;
                dfs1(node,vis,adjR);
            }
        }
        return ans;
        
    }
};
