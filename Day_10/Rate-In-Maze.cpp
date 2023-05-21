class Solution{
    private:
    void fun(int i,int j,vector<vector<int>> &maze,string s,int n,
            vector<vector<int>> &vis,vector<string>&ans)
    {
        
        if(i == n-1 && j == n-1)
        {
            ans.push_back(s);
            return;
        }
        
        // down
        if(i+1<n && !vis[i+1][j] && maze[i+1][j]==1)
        {
            vis[i][j] = 1;
            fun(i+1,j,maze,s+'D',n,vis,ans);
            vis[i][j] = 0;
        }
        // left
        if(j-1>=0 && !vis[i][j-1] && maze[i][j-1] == 1)
        {
            vis[i][j] = 1;
            fun(i,j-1,maze,s+'L',n,vis,ans);
            vis[i][j] = 0;
        }
        // right
        if(j+1<n && !vis[i][j+1] && maze[i][j+1] == 1)
        {
            vis[i][j] = 1;
            fun(i,j+1,maze,s+'R',n,vis,ans);
            vis[i][j] = 0;
        }
        // up
        if(i-1>=0 && !vis[i-1][j] && maze[i-1][j] == 1)
        {
            vis[i][j] = 1;
            fun(i-1,j,maze,s+'U',n,vis,ans);
            vis[i][j] = 0;
        }
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>ans;
        string s = "";
        if(m[0][0] == 1){
            fun(0,0,m,s,n,vis,ans);
            return ans;    
        }
        return {"-1"};
        
    }
    
};
