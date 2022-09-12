class Solution {
public:
    int partitionString(string s) {
        set<char> st;
        int count=0, n=s.length();
        for(int i=0;i<n;i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
            }else{
                count++;
                st.clear();
                st.insert(s[i]);
            }
        }
        if(!st.empty()) count++;
        
        return count;
    }
};