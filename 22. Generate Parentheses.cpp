class Solution {
    vector<string> s;
public:
    
    void solve(string combi, int n, int mimicStack) {
        if(n == 0 && mimicStack == 0)
            s.push_back(combi);
        
        if(n > 0)
            solve(combi + '(', n-1, mimicStack+1);

        if(mimicStack > 0)
            solve(combi + ')', n, mimicStack-1);
    }
    
    vector<string> generateParenthesis(int n) {
        solve("", n, 0);
        return s;
    }
};
