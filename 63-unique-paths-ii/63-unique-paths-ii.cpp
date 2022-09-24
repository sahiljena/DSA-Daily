class Solution {
public:
    int paths(int i, int j, vector<vector<int>>&dp,vector<vector<int>>&grid){
        if(i<0 || j<0) return 0;
        if(grid[i][j]!=0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return 1;
        int up = paths(i-1,j,dp,grid);
        int left = paths(i,j-1,dp,grid);
        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(1001, vector<int>(1001,-1));
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        return paths(m-1,n-1, dp, obstacleGrid);
    }
};