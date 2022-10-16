class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int> mp;
        for(int i:nums) mp[i]++;
        int ans=-1;
        for(int i:nums){
            if(mp.find(-i)!=mp.end()) ans=max(ans,i);
        }
        return ans;
    }
};