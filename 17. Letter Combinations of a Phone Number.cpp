class Solution 
{
public:
    void helper(string digit,string tmp,vector<string>&v,vector<string>&aux,int index)
    {
        if(index==digit.length())
        {
            v.push_back(tmp);
            return;
        }
        for(int i=0;i<aux[digit[index]-'0'].length();i++)
        {
            tmp.push_back(aux[digit[index]-'0'][i]);
            helper(digit,tmp,v,aux,index+1);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.length()==0)
        {
            return {};
        }
        vector<string>aux={"","","abc","def","ghi","jkl","mno","prqs","tuv","wxyz"},ans;
        helper(digits,"",ans,aux,0);
        return ans;
    }
};
