class Solution {
public:
    int bin(string x)
    {
        int num = 0;
        for(auto c:x)
        {
            num = num*2  + (c-'0');
        }
        return num;
    }
    vector<string> solve(int n)
    {
        if(n==1)
        {
            return {"0","1"};
        }
        vector<string>temp = solve(n-1);
        vector<string>res;
        for(int i=0;i<temp.size();i++)
        {
            string curr = "0"+temp[i];
            res.push_back(curr);
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            string curr = "1"+temp[i];
            res.push_back(curr);
        }
        return res;
    }
    vector<int> grayCode(int n) {
        vector<string>ans = solve(n);
        vector<int>v;
        for(auto x:ans)
        {
            v.push_back(bin(x));
        }
        return v;
    }
};
