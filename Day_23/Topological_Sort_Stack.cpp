class Solution
{
    private :
    void dfs(int start,vector<int>adj[],stack<int>&s,int vis[])
    {
        vis[start] =1;
        for(auto i : adj[start])
        {
            if(!vis[i])
            {
                dfs(i,adj,s,vis);
            }
        }
        s.push(start);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>s;
	    int vis[V] = {0};
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	             dfs(i,adj,s,vis);
	    }
	    vector<int>ans;
	    while(s.size()!= 0)
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};
