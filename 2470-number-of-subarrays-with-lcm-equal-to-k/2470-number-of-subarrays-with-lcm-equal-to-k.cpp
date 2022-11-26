class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt=0, lst=1;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                lst = lcm(lst, nums[j]);
                if(lst==k) ++cnt;
                if(lst>k) break;
            }
            lst=1;
        }
        return cnt;
    }
};