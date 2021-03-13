class Solution {
public:
    string getPermutation(int n, int k) {
        // 4 bits -> possible permutations = 4*3*2*1 = 24
        // n=4 -> first number permutations = 1234,1243,1324,1342,1423,1432
        // ->second number permutations = 2134,2143,2314,2341,2413,2431
        // hence the k=9 here is "2314"
        // so from here we can get the number of permutations start with 1 is 6
        // number of permutation start with 2,3,4 are 6,6,6 respectivly
        int fact = 1;
        vector<int>arr;
        for(int i=1;i<n;i++)
        {
            fact=fact*i;
            arr.push_back(i);
        }
        arr.push_back(n);
        k=k-1;
        string ans = "";
        while(true)
        {
            ans = ans+to_string(arr[k/fact]);
            arr.erase(arr.begin()+k/fact);
            if(arr.size()==0)
            {
                break;
            }
            k= k%fact;
            fact=fact/arr.size();
        }
        return ans;
    }
};
