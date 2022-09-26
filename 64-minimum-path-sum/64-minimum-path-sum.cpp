class Solution {
public:
    int pathSum(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&dp){
        
        if(i<0 || j<0) return INT_MAX;
        if(i==0&&j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = pathSum(grid,i-1,j,dp);
        int left = pathSum(grid,i,j-1,dp);
        return dp[i][j]=grid[i][j]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n=grid[0].size();
        vector<vector<int>> dp(1001, vector<int>(1001,INT_MAX));
        // return pathSum(grid, m-1, n-1, dp);
        int minPath=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){ 
                    dp[i][j]=grid[0][0];
                }
                else{
                    int right=INT_MAX, down=INT_MAX;
                    if(i>0) down=grid[i][j]+dp[i-1][j];
                    if(j>0) right=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(right,down);
                }
            }
        }
        return dp[m-1][n-1];
    }
};