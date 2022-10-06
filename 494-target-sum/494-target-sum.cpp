class Solution {
public:
    map<pair<int,int>,int> dp;
    int findWays(vector<int>&nums, int target, int curr, int index){
        if(index==nums.size()){
            if(curr==target) return 1;
            return 0;
        }
        if(dp.find({curr, index})!=dp.end()) return dp[{curr, index}];
        int take = findWays(nums, target, curr+nums[index], index+1);
        int notake = findWays(nums, target, curr-nums[index], index+1);
        return dp[{curr, index}] = take+notake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return findWays(nums, target, 0, 0);
    }
};