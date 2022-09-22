class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp;
        for(char i:s){
            if(isspace(i)){
                if(temp.length()){
                    reverse(temp.begin(), temp.end());
                    ans+=temp;
                    temp="";
                }
                ans+=i;
            }
            else{
                temp+=i;
            }
        }
        if(temp.length()){
            reverse(temp.begin(), temp.end());
            ans+=temp;
            temp="";
        }
        return ans;
    }
};