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
        // int mini=INT_MAX;
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j] = matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==n-1){
                    dp[i][j] = matrix[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
                }
                else{
                    dp[i][j] = matrix[i][j]+min({dp[i-1][j], dp[i-1][j+1], dp[i-1][j-1]});
                }

            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini, dp[m-1][j]);
        }
        return mini;
    }
};