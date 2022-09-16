class Solution {
public:
    
    int helper(vector<int>&num, vector<int>&mul, int l, int r, int i, vector<vector<int>>&dp){
        if(i==mul.size()) return 0;
        if(dp[l][i]!=INT_MIN) return dp[l][i];
        
        int lf = mul[i]*num[l]+helper(num,mul,l+1,r,i+1,dp);
        int rf = mul[i]*num[r]+helper(num,mul,l,r-1,i+1,dp);
        
        return dp[l][i]=max(lf,rf);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n=nums.size(), m = mul.size();
        vector<vector<int>> dp(m,vector<int>(m,INT_MIN));
        return helper(nums,mul,0,nums.size()-1,0,dp);
    }
};