class Solution {
public:
    void solve(int row, vector<vector<string>>& res, vector<bool>& col,vector<bool>& left_d, vector<bool>& right_d, vector<string>& board)
    {
        if(row==col.size())
        {
            res.push_back(board);
            return;
        }
        int k = col.size()-1;
        for(int i=0;i<col.size();i++)
        {
            if(!col[i] && !left_d[row-i+k] && !right_d[row+i])
            {
                board[row][i] = 'Q';
                col[i] = true;
                left_d[row-i+k] = true;
                right_d[i+row] = true;
                solve(row+1,res,col,left_d,right_d,board);
                board[row][i] = '.';
                col[i] = false;
                left_d[row-i+k] = false;
                right_d[i+row] = false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>res;
        // vector<string>ans;
        vector<bool> col(n,false);
        vector<bool> left_d(2*n-1,false);
        vector<bool> right_d(2*n-1,false);
        int y=n;
        string s="";
        vector<string> board;
        while(y--){
            s.push_back('.');
        }
        for(int i=0;i<n;i++){
           board.push_back(s);
        } 
        // call the solve function with the first row
        solve(0,res,col,left_d,right_d,board);
        return res.size();
    }
    
};
