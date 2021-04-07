class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int ind,int x,int y,int n,int m)
    {
        if(ind==word.length())
        {
            return true;
        }
        if(x<0 || y<0 || x>=n || y>=m || board[x][y]=='.' || word[ind]!=board[x][y])
        {
            return false;
        }
        char temp = board[x][y];
        board[x][y] = '.';
        
        if(solve(board,word,ind+1,x+1,y,n,m))
        {
            return true;
        }
        
        
        if(solve(board,word,ind+1,x-1,y,n,m))
        {
            return true;
        }
        
        
        if(solve(board,word,ind+1,x,y+1,n,m))
        {
            return true;
        }
        
        
        if(solve(board,word,ind+1,x,y-1,n,m))
        {
            return true;
        }
        board[x][y] = temp;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solve(board,word,0,i,j,n,m)==true)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
