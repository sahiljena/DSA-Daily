class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        map<string,long> mpv;
        map<string,set<pair<long,string>>>mpc;

        for(int i=0;i<n;i++){
            mpv[creators[i]]+=views[i];
            mpc[creators[i]].insert({-views[i],ids[i]});
        }
        
        long high=0;
        vector<vector<string>>ans;
        for(auto i:mpv){
            high=max(high,i.second);
        }
        for(auto i:mpv){
            if(i.second==high){
                string creator = i.first;
                string creatorHighestId = mpc[creator].begin()->second;
                ans.push_back({creator,creatorHighestId});
            }
        }
        return ans;
    }
};