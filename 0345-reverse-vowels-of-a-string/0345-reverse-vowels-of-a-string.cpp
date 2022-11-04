class Solution {
public:
    string reverseVowels(string s) {
        map<char,int> mp;
        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;
        mp['A']=1;
        mp['E']=1;
        mp['I']=1;
        mp['O']=1;
        mp['U']=1;
        
        int i = 0;
        int j = s.length()-1;
        while(i<=j){
            if(mp.find(s[i])!=mp.end() && mp.find(s[j])!=mp.end()){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(mp.find(s[i])!=mp.end() && mp.find(s[j])==mp.end()){
                j--;
            }
            else if(mp.find(s[i])==mp.end() && mp.find(s[j])!=mp.end()){
                i++;
            }else{
                i++;
                j--;
            }
        }
        return s;
    }
};