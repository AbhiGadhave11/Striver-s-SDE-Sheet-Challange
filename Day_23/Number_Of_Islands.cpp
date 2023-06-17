class Solution {
    private:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis,int n,int m)
    {
        vis[row][col] = 1;
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
            {
                dfs(nrow,ncol,grid,vis,n,m);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int cnt =0 ,n = grid.size(),m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    cnt++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return cnt;
        
    }
};
