class Solution {
public:
    int numSteps(string s) {
        int carry = 0, res = 0;
        for(int i=s.length()-1;i>0;--i){
            ++res;
            if(s[i]-'0'+carry==1){
                carry=1;
                ++res;
            }
        }
        return res+carry;
    }
};