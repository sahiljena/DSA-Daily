class Solution {
public:
    int minPaths(vector<vector<int>>& tri, int i, int j, vector<vector<int>>&dp){
        if(i>tri.size()-1 || j>tri[i].size()-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = tri[i][j]+minPaths(tri,i+1,j, dp);
        int left = tri[i][j]+minPaths(tri,i+1,j+1, dp);
        return dp[i][j] = min(right,left);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n=triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return minPaths(triangle, 0, 0, dp);
    }
};