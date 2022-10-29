class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zCnt = 0, prod=1;
        for(int i:nums){
            if(i==0) zCnt++;
            else prod*=i;
        }
        vector<int> ans(nums.size(),0);
        if(zCnt>1) return ans;
        for(int i=0;i<nums.size();i++){
            if(zCnt && nums[i]!=0) continue;
            if(nums[i]==0) ans[i]=prod;
            else ans[i]=prod/nums[i];
        }
        return ans;
    }
};