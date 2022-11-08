class Solution {
public:
    string makeGood(string s) {
        string ans="";
        int i=0;
        while(i<s.length()){
            if(s[i]==tolower(s[i+1]) && s[i]!=s[i+1]){
                i+=2;
                continue;
            }
            else{ 
                int n = ans.length();
                if(n>=1 && ans[n-1]!=s[i] && tolower(ans[n-1])==tolower(s[i])){
                    ans.erase(ans.begin()+(n-1));
                    i++;
                }
                else{ 
                    ans+=s[i];
                    i++;
                }
            }
        }
        return ans;
    }
};