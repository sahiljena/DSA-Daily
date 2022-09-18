class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0, cnt=1;
        for(int i=1;i<s.length();i++){
            if(s[i-1]-'a'+1==s[i]-'a'){
                cnt+=1;
                ans=max(ans,cnt);   
            }else cnt=1;
        }
        return ans?ans:1;
    }
};