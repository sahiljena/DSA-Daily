class Solution {
public:
    int paths(int i, int j, vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return 1;
        int up = paths(i-1,j,dp);
        int left = paths(i,j-1,dp);
        return dp[i][j] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        return paths(m-1,n-1,dp);
    }
};