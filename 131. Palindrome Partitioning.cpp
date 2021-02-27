class Solution {
public:
    bool ispalindrome(string left)
    {
        int i=0;
        int j=left.length()-1;
        while(i<j)
        {
            if(left[i]!=left[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s, vector<string>& temp, vector<vector<string>>& res)
    {
        if(s.length()==0)
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<s.length();i++)
        {
            string left = s.substr(0,i+1);
            string right = s.substr(i+1);
            if(ispalindrome(left)==true)
            {
                temp.push_back(left);
                solve(right,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        solve(s,temp,res);
        return res;
    }
};
