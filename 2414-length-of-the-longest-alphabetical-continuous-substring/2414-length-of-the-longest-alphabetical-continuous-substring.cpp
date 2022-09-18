class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0, cnt=1;
        vector<int> arr;
        for(char i:s) arr.push_back(i-'a');
        for(int i=1;i<s.length();i++){
            if(arr[i-1]+1==arr[i]){
                cnt+=1;
                ans=max(ans,cnt);   
            }else cnt=1;
        }
        return ans?ans:1;
    }
};