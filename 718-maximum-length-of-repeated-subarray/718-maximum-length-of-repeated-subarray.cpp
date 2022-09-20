class Solution {
public:
    int dp[1001][1001];
    
    int helper(vector<int>&nums1, vector<int>&nums2, int n, int m){
        if(n<0 || m<0) return 0;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        helper(nums1, nums2, n-1, m);
        helper(nums1, nums2, n, m-1);
        
        if(nums1[n]==nums2[m]){
            return dp[n][m]=helper(nums1,nums2,n-1,m-1)+1;
        }else return dp[n][m]=0;
    }
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++) dp[i][j]=-1;
        }
        
        helper(nums1, nums2, n-1, m-1);
        
        int max1 = 0;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++) max1=max(max1,dp[i][j]);
        }
        return max1;
    }
};