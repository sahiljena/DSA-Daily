class Solution {
public:
    int longestContinuousSubstring(string s) {
        if(s.length()==1) return 1;
        int ans = 0;
        vector<int> arr;
        for(char i:s) arr.push_back(i-'a');
        int cnt=1;
        for(int i=1;i<s.length();i++){
            if(arr[i-1]+1==arr[i]){
                cnt+=1;
                ans=max(ans,cnt);   
            }else cnt=1;
        }
        return ans==0?1:ans;
    }
};