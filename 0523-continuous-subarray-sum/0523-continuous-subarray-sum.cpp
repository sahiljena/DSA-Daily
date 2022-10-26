class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        unordered_map<int,int>mp;
        int n = nums.size();
        int sum = 0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            sum%=k;
            if(mp.find(sum)!=mp.end()){
                if(i-mp[sum]>1) return true;
            }
            else{
                mp[sum]=i;
            }
        }
        return false;
    }
};