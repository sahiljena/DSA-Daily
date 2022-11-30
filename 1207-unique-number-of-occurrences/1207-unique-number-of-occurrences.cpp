class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp, revmp;
        for(int i: arr) mp[i]++;
        
        for(auto i:mp){
            if(revmp.find(i.second)!=revmp.end()) return false;
            else{
                revmp[i.second]=i.first;
            }
        }
        return true;
    }
};