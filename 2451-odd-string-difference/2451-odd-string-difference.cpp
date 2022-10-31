class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>,int>mp;
        map<vector<int>,string>mp2;
        for(string word:words){
            vector<int>diff;
            for(int i=1;i<word.length();i++){
                diff.push_back((word[i]-'a')-(word[i-1]-'a'));
            }
            mp[diff]++;
            mp2[diff]=word;
        }
        string ans;
        for(auto i:mp){
            if(i.second==1){
                ans=mp2[i.first];
                break;
            }
        }
        return ans;
        
    }
};