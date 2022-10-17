class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length()<26) return false;
        string s = "abcdefghijklmnopqrstuvwxyz";
        map<char,int> mp;
        for(char c:sentence) mp[c]++;
        for(char c:s){
            if(mp.find(c)==mp.end()) return false;
        }
        return true;
    }
};