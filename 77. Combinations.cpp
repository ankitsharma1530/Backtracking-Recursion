/* traditonal way

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int>ans, int k,int ind){
        if(k==ans.size()){
            res.push_back(ans);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            ans.push_back(nums[i]);
            solve(nums,res,ans,k,i+1);
            ans.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<vector<int>>res;
        vector<int>ans;
        solve(nums,res,ans,k,0);
        return res;
    }
};

*/

// time complexity -> O(n^min(k,n-k))
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        if(n<k)return res;
        vector<int> temp(0,k);
        combine(res,temp,0,0,n,k);
        return res;
    }
    
void combine(vector<vector<int>> &res,vector<int> &temp,int start,int num,int n ,int k){
        if(num==k){
            res.push_back(temp);
            return;
        }
        for(int i = start;i<n;i++){
            temp.push_back(i+1);
            combine(res,temp,i+1,num+1,n,k);
            temp.pop_back();
            }
        }
};
