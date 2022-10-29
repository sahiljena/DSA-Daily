class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if(n!=m) return false;
        
        map<char,char>m1;
        map<char,char>m2;
        for(int i=0;i<n;i++){
            if(m1.find(s[i])==m1.end() && m2.find(t[i])==m2.end()){
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
        }
        for(int i=0;i<n;i++){
            if(m1[s[i]]!=t[i] || m2[t[i]]!=s[i]) return false;
        }
        return true;
    }
};