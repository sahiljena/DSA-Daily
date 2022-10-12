class Solution {
public:
    int n,m;
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        if(j>=n || j<0) return INT_MAX;
        if(i==m-1) return matrix[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int dr = helper(i+1,j-1,matrix,dp);
        int d = helper(i+1,j,matrix,dp);
        int dl = helper(i+1,j+1,matrix,dp);
        return dp[i][j]=min(d,min(dr,dl))+matrix[i][j];
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini, helper(0,i,matrix,dp));
        }
        return mini;
    }
};