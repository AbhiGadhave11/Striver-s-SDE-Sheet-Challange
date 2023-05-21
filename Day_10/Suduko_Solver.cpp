class Solution {
    private:
    bool isValid(vector<vector<char>>&board,int row,int col,char ch)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[i][col] == ch)
                return false;
            if(board[row][i] == ch)
                return false;
            int gridrow = 3*(row/3)+i/3;
            int gridcol = 3*(col/3)+i%3;
            if(board[gridrow][gridcol] == ch)
                return false;
        }
        return true;
    }
    
    bool Solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == '.')
                {
                    for(int ch='1';ch<='9';ch++)
                    {
                        if(isValid(board,i,j,ch))
                        {
                            board[i][j] = ch;
                            if(Solve(board) == false)
                            {
                                board[i][j] = '.';
                            }
                            else
                                return true;
                        }
                    }
                    return false;
                }
            }
            
        }
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        
        Solve(board);
    }
};
