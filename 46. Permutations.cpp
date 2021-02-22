class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int>& ans , vector<bool>vis)
    {
        if(ans.size()==nums.size())
        {
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]==true)
            {
                continue;
            }
            ans.push_back(nums[i]);
            vis[i]=true;
            solve(nums,res,ans,vis);
            // backtrack
            vis[i]=false;
            ans.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        vector<bool>vis(nums.size(),false);
        solve(nums,res,ans,vis);
        return res;
    }
};
