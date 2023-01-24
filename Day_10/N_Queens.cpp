
bool issafe(vector<vector<int>>&v,int row,int col)
{
    for(int i=0;i<8;i++)
    {
        if(v[row][i] == 1 || v[i][col] == 1)
            return false;
    }
    for(int i=row,j = col;i>=0&&j>=0 ; i--,j--)
    {
        if(v[i][j] == 1)
            return false;
    }
    for(int i = row,j=col;i<8&&j>=0 ;i++,j--)
    {
        if(v[i][j] == 1)
            return false;
    }

    return true;
}

int fun(vector<vector<int>>&v,int col)
{
    if(col == 8)
        return 1;
    int ans = 0;
    for(int row = 0;row<8;row++)
    {
        if(v[row][col] == -1)
            continue;
        if(issafe(v,row,col) == true)
        {
            v[row][col] = 1;
            ans = ans + fun(v,col+1);
            v[row][col] = 0;
        }
    }
    return ans;

}
