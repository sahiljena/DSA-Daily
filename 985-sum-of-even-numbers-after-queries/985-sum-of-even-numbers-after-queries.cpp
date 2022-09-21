class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int evenSum=0;
        for(int i:nums){
            if(i%2==0) evenSum+=i;
        }
        for(auto i:queries){
            if(nums[i[1]]%2==0){
                if((nums[i[1]]+i[0])%2!=0){
                    evenSum-=nums[i[1]];
                    nums[i[1]]+=i[0];
                    ans.push_back(evenSum);
                }else{
                    evenSum+=i[0];
                    nums[i[1]]+=i[0];
                    ans.push_back(evenSum);
                }
            }else{
                if((nums[i[1]]+i[0])%2==0){
                    evenSum+=(nums[i[1]]+i[0]);
                    nums[i[1]]+=i[0];
                    ans.push_back(evenSum);
                }else{
                    nums[i[1]]+=i[0];
                    ans.push_back(evenSum);
                }
            }
        }
        return ans;
    }
};