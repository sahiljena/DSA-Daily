class Solution {
public:
    int mod = 1e9+7;
    int helper(int sum, int k, int i, int j, vector<vector<int>>&grid,  vector<vector<vector<int>>>&dp){
        if(i<0 || j<0) return 0;
        if(i==0 && j==0){
            if((grid[0][0]+sum)%k==0) return 1;
            return 0;
        }
        sum=sum%k;
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        int &final = dp[i][j][sum];
        sum = (sum%k + grid[i][j]%k)%k;
        int up = helper(sum,k,i-1,j,grid,dp)%mod;
        int left = helper(sum,k,i,j-1,grid,dp)%mod;
        return final = (up+left)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m;i++){
            for(int j = 0;j < n ;j++){
                grid[i][j] = grid[i][j]%k;
            }
        }
        vector<vector<vector<int>>> dp(m+1 , vector<vector<int>>(n+1, vector<int> (k , - 1)));
        return helper(0,k,m-1,n-1,grid,dp);
    }
};