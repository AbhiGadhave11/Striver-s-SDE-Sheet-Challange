class Solution {
    private :
    bool isvalid(vector<vector<string>>&queen,int n,int row,int col)
    {
        for(int i=0;i<n;i++){
            if(queen[i][col] == "Q" || queen[row][i] == "Q")
                return false;
        }
        for(int i=row,j = col;i>=0&&j>=0 ; i--,j--)
        {
            if(queen[i][j] == "Q")
                return false;
        }
        for(int i = row,j=col;i<n&&j>=0 ;i++,j--)
        {
            if(queen[i][j] == "Q")
                return false;
        }

        return true;
    }
    vector<vector<string>>ans;
    void fun(vector<vector<string>>&queen,int n,int col)
    {
        if(col >= n)
        {
            vector<string>v;
            
            for(auto &it : queen){
                string s;
                for(auto &it1 : it){
                    s = s + it1;
                }
                v.push_back(s);
            }
            ans.push_back(v);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(isvalid(queen,n,i,col) == true)
            {
                queen[i][col] = "Q";
                fun(queen,n,col+1);
                queen[i][col] = ".";
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>queen(n,vector<string>(n,"."));
        fun(queen,n,0);
        return ans;
        
    }
};