class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0) return {};
        unordered_map<int,int> mp;
        for(int i:changed) mp[i]++;
        vector<int> ans;
        for(int i=0;i<mp[0]/2;i++){
            ans.push_back(0);
        }
        sort(changed.begin(),changed.end());
        for(int i:changed){
            if(i!=0 && mp.find(i*2)!=mp.end()){
                for(int j=0;j<mp[i];j++){
                    if(mp[i*2]<1) break;
                    ans.push_back(i);
                    mp[i*2]--;
                    mp[i]--;
                }
            }
        }
        // for(auto i:ans) cout<<i<<" ";
        // cout<<endl;
        if(ans.size()==changed.size()/2) return ans;
        return {};
    }
};