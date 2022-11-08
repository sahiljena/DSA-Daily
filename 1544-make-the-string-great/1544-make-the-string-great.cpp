class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        
        for(int i=0;i<s.length();i++){
            if(st.empty()) st.push(s[i]);
            else{
                char temp = st.top();
                if(temp!=s[i] && tolower(temp)==tolower(s[i])){
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty()){
            char temp = st.top();
            st.pop();
            ans+=temp;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};