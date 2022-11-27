class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0, j=0;
        int n=s.length(), m=t.length();
        
        while(i<n || m<j){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else if(s[i]!=t[j]){
                i++;
            }
        }
        return m-j;
    }
};