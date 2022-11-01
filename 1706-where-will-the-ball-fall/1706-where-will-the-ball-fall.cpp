class Solution {
public:
    int m = 0;
    int n = 0;
    void fans(vector<vector<int>>&grid, int i, int j, vector<int>&ans){
        if(i==m){
            ans.push_back(j);
            return;
        }
        if(grid[i][j]==1){
            if((j==n-1)||(j<n-1 && grid[i][j+1]==-1)){
                ans.push_back(-1);
                return;
            }
            else fans(grid,i+1,j+1,ans);
        }else{
            if((j==0)||(j>0 && grid[i][j-1]==1)){
                ans.push_back(-1);
                return;
            }
            else fans(grid,i+1,j-1,ans);
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            fans(grid, 0, i, ans);
        }
        return ans;
    }
};