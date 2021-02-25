class Solution {
public:
    
   static bool comp(string &s1 , string &s2){
        return (s1+s2) >= (s2+s1);
   }
    string largestNumber(vector<int>& nums) {
        int  n = nums.size();
        if(n==1)
            return to_string(nums[0]);
        int count=0;
        for(int x : nums)
            if(x==0)
                count++;
        if(count == n)
            return "0";
        vector<string> s(n,"");
        for(int i=0;i<n;i++)
            s[i] = to_string(nums[i]);
        
        sort(s.begin() , s.end() , comp);
        string ans ="";
        for(int i=0;i<n;i++)
            ans+= s[i];
        return ans;        
    }
};
