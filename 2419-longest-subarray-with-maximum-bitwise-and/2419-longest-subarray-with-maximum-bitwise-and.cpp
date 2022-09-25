class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElem = 0;
        int ans = 1;
        for(int i:nums) maxElem=max(i, maxElem);
        
        int lctemp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxElem){
                lctemp+=1;
                ans=max(ans,lctemp);
            }
            else lctemp=0;
        }
        return ans;
    }
};