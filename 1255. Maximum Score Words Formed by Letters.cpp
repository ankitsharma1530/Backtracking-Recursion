class Solution {
public:
    int solve(vector<string>& words,vector<int>& score,vector<int>& f,int index)
    {
        if(index>=words.size())
        {
            return 0;
        }
        int not_choose = solve(words,score,f,index+1);
        int choose = 0;
        bool check_if_current_can_fit = true;
        int score_of_current_word=0;
        for(int i=0;i<words[index].length();i++)
        {
            if(f[words[index][i]-'a']<=0)
            {
                check_if_current_can_fit = false;
            }
            f[words[index][i]-'a']--;
            score_of_current_word += score[words[index][i]-'a'];
        }
        if(check_if_current_can_fit)
        {
            choose = score_of_current_word+solve(words,score,f,index+1);
        }
        // backtrack
        for(int i=0;i<words[index].length();i++){
           char c=words[index][i];
           f[c-'a']++;   
       }
        return max(choose,not_choose);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // unordered_map<>
        // count all the frequencies of the elements
        vector<int>f(26,0);
        for(int i=0;i<letters.size();i++)
        {
            f[letters[i]-'a']++;
        }
        return solve(words,score,f,0);
    }
};
