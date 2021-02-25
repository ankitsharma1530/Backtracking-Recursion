// class Solution {
// public:
//     int maximumSwap(int num) {
//         int arr[10]={0};
//         string temp = to_string(num);
//         for(int i=0;i<temp.length();i++)
//         {
//             arr[temp[i]-'0'] = i;
//         }
//         for(int i=0;i<temp.length();i++)
//         {
//             for(int j=9;j>temp[j]-'0';j--)
//             {
//                 if(arr[j]>i)
//                 {
//                     swap(temp[i],temp[arr[j]]);
//                     int res = stoi(temp);
//                     return res;
//                 }
//             }
//         }
//         return num;
//     }
// };

class Solution {
public:
    int maximumSwap(int num) {
        int mxIdx=-1,mxDigit=-1,leftIdx=-1,rightIdx=-1;
        string s=to_string(num);
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]>mxDigit){
                mxDigit=s[i];
                mxIdx=i;
                continue;
            }
            if(s[i]<mxDigit){
                leftIdx=i;
                rightIdx=mxIdx;
            }
        }
        if(leftIdx==-1)return num;
        swap(s[leftIdx],s[rightIdx]);
        return stoi(s);
    }
};
