class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> kp;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            kp[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto i: kp){
            sort((i.second).begin(),(i.second).end());
            ans.push_back(i.second);
        }
        return ans;
    }
};