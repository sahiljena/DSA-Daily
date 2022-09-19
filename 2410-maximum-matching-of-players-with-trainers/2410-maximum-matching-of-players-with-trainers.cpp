class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        
        int n = players.size();
        int m = trainers.size();
        
        int ans =0, i=0,j=0;
        // for(auto i:players) cout<<i<<" ";cout<<endl;
        // for(auto j:trainers) cout<<j<<" ";cout<<endl;
        while(i<n){
            if(j>=m) break;
            if(players[i]<=trainers[j]){
                ans++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return ans;
        
        
        
    }
};