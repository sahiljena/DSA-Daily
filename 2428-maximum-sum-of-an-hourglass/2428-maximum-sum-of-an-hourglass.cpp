class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int maxSum=INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(i+2>=m) break;
                if(j+2>=n) break;
                
                int tempSum=0;
                for(int k=j;k<j+3;k++) tempSum+=grid[i][k];
                for(int k=j;k<j+3;k++) tempSum+=grid[i+2][k];
                tempSum+=grid[i+1][j+1];
                
                maxSum = max(maxSum, tempSum);
                
            }
        }
        
        return maxSum;
        
    }
};