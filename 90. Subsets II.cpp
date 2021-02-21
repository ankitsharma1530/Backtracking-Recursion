class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& res, int i)
    {
        ans.push_back(res);
        for(int j=i;j<nums.size();j++)
        {
            if(i==j || nums[j]!=nums[j-1])
            {
                res.push_back(nums[j]);
                solve(nums,ans,res,j+1);
                res.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // to avoid duplicates use sort
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>res;
        solve(nums,ans,res,0);
        return ans;
    }
};
