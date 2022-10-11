class Solution {
public:
    int dp[8000][71];
    int n,m;
    int helper(int i, int sum, vector<vector<int>>&mat, int target){
        if(i>=m){
            return abs(sum-target);
        }
        if(dp[sum][i]!=-1) return dp[sum][i];
        int minDiff=INT_MAX;
        for(int j=0;j<n;j++){
            minDiff=min(minDiff,helper(i+1,sum+mat[i][j], mat, target));
            if(minDiff==0) break;
        }
        return dp[sum][i]=minDiff;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m = mat.size();
        n = mat[0].size();
        memset(dp,-1,sizeof(dp));
        return helper(0,0,mat,target);
    }
};