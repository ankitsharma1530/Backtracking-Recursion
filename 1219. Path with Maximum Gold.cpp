class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<bool>>& vis)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || vis[i][j]==true)
        {
            return 0;
        }
        vis[i][j]=true;
        int s = grid[i][j];
        s = s+max({solve(grid,i+1,j,n,m,vis),solve(grid,i-1,j,n,m,vis),solve(grid,i,j-1,n,m,vis),solve(grid,i,j+1,n,m,vis)});
        vis[i][j]=false;
        return s;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    int res = solve(grid,i,j,n,m,vis);
                    ans = max(ans,res);
                }
            }
        }
        return ans;
    }
};
