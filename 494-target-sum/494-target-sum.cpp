class Solution {
public:
    int findWays(vector<int>&nums, int target, int curr, int index){
        if(index==nums.size()){
            if(curr==target) return 1;
            return 0;
        }
        int tk = findWays(nums, target, curr+nums[index], index+1);
        int ntk = findWays(nums, target, curr-nums[index], index+1);
        return tk+ntk;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return findWays(nums, target, 0, 0);
    }
};