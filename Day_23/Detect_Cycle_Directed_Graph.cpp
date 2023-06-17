class Solution {
    private:
    bool dfs(int node,vector<int>adj[],vector<int>&vis,int parent,vector<int>&currvis)
    {
        vis[node] = 1;
        currvis[node] = 1;
        for(auto &it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,node,currvis))
                    return true;
            }
            else if(vis[it] && currvis[it])
            {
                return true;
            }
        }
        currvis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto &it : prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
           ]
        }
        
        vector<int>vis(numCourses,0);
        vector<int>currvis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i]){
                
             if(dfs(i,adj,vis,-1,currvis))
                return false;
            }
        }
       
        return true;
    }
};





