class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        stringstream ss(s1);
        string word;
        map<string,int> mp;
        while(ss>>word) mp[word]++;
        stringstream ss2(s2);
        while(ss2>>word) mp[word]++;
        
        for(auto i:mp){
            if(i.second==1) ans.push_back(i.first);
        }
        return ans;
    }
};