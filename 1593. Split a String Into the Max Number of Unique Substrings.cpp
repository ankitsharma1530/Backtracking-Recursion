// how we got to know this is a backtracking question
// see here we had to make subtring or combinations 
// which we can only do with the help of backtracking 
// hence we gonnna use backtracking


class Solution {
public:
    int res = 0;
    void solve(string s, unordered_set<string> st, int ind,int a){
        if(ind==s.length()){
            res = max(res,(int)st.size());
            return;
        }
        for(int i=ind;i<s.length();i++){
            
            // the way to create substr
            // i.e from abcd -> a,ab,abc,abcd
            string temp = s.substr(ind,i-ind+1);
            if(st.find(temp)==st.end()){
                st.insert(temp);
                solve(s,st,i+1,a);
                st.erase(temp);
            }
        }
        
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        solve(s,st,0,0);
        return res;
    }
};

// time complexity -> O(n * 2^n) because at every point, we can either choose to spilt or not. After every split, we go till string end i.e. n;


// this is the solution where we do not use substr
// here we create a string that act as a substring
class Solution {
public:
    unordered_set<string>st;
    int ans=0;
    void dfs(string &s, int idx)
    {
        if(st.size()>ans) ans=st.size();
        if(idx>=s.length()) return;
        
        // this str will act as a substring
        
        // we will use this to create substring
        // every index has its own str ="";
        // exp-> s = "abcd"
        // for 0th index str = a,ab,abc,abcd
        // for 1th index str = b,bc,bcd
        // for 2nd index str = c,cd
        string str="";
        for(int i=idx ; i<s.length() ; i++)
        {
            str += s[i];
            if(st.find(str)==st.end())
            {
                st.insert(str);
                dfs(s,i+1);
                st.erase(str);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        dfs(s,0);
        return ans;
    }
};
