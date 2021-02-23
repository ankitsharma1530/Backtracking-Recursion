class Solution {
public:
    bool check(vector<vector<char>>& board, int m, int n, int c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][n]==c)
            {
                return false;
            }
        }
        for(int j=0;j<9;j++)
        {
            if(board[m][j]==c)
            {
                return false;
            }
        }
        for(int i=3*(m/3);i<3*(m/3)+3;i++)
        {
            for(int j=3*(n/3);j<3*(n/3)+3;j++)
            {
                if(board[i][j]==c)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int m, int n)
    {
        // if we reached at end
        if(m==8 && n==9)
        {
            return true;
        }
        if(n==9)
        {
            m++;
            n=0;
        }
        if(board[m][n]=='.')
        {
            // now check for all possible values
            for(int l=1;l<=9;l++)
            {
                char c = l+'0';
                if(check(board,m,n,c))
                {
                    board[m][n] = c;
                    if(solve(board,m,n+1))
                    {
                        return true;
                    }
                    board[m][n] = '.';
                }
            }
           
        }
        else
        {
            if(solve(board,m,n+1))
            {
                return true;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};
