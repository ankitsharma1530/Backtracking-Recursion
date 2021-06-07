class Solution {
public:
    bool isvalid(string temp){
        unordered_set<char>st;
        for(int i=0;i<temp.size();i++){
            if(st.find(temp[i])!=st.end()){
                return false;
            }
            st.insert(temp[i]);
        }
        return true;
    }
    void solve(string temp, vector<string>& arr, int ind, int& ans){
        // first we will check wether our temp sting is unique or not
        if(isvalid(temp)==false){
            return;
        }
        int size = temp.size();
        ans = max(ans,size);
        for(int i=ind;i<arr.size();i++){
            solve(temp+arr[i],arr,i+1,ans);
        }
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        solve("",arr,0,ans);
        return ans;
    }
};
