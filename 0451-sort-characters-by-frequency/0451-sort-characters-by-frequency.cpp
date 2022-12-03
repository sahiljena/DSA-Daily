class Solution {
        static bool comp(pair<char, int> a, pair<char, int> b){
        return a.second>b.second;
    }
public:
    string frequencySort(string s) {
        map<char,int> mp;
        vector<pair<char,int>> arr;
        string ans;
        
        
        for(char c:s) mp[c]++;
        for(auto i:mp){
            arr.push_back({i.first, i.second});
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        for(auto i:arr){
            while(i.second--) ans+=i.first;
        }
        
        return ans;
    }
};