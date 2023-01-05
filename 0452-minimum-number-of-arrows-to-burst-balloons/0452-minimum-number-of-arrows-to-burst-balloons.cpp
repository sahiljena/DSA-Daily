bool cmp(vector<int>&a, vector<int>&b){ return a[1]<b[1];}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.size()==0) return 0;
        
        sort(points.begin(), points.end(), cmp);
        
        int ans = 1;
        
        int arrow = points[0][1];
        
        for(int i=0;i<points.size();i++){
            if(arrow>=points[i][0] && arrow<=points[i][1]) continue;
            
            ans++;
            arrow = points[i][1];
        }
        
        return ans;
        
    }
};