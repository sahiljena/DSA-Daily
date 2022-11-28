class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> winners;
        vector<int> loosers;
        map<int,pair<int,int>> mp; // key -> {won, lost} ;
        
        
        for(auto i:matches){
            if(mp.find(i[0])!=mp.end()){
                mp[i[0]].first+=1;
            }else{
                mp[i[0]] = {1,0};
            }
            
            if(mp.find(i[1])!=mp.end()){
                mp[i[1]].second+=1;
            }else{
                mp[i[1]] = {0,1};
            }
        }
        
        for(auto i:mp){
            if(i.second.second==0) winners.push_back(i.first);
            if(i.second.second==1) loosers.push_back(i.first);
        }

        return {winners,loosers};
    }
};