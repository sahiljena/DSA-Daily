class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int count = 0;
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<heights[i]){
                count++;
                st.pop();
            }
            ans[i]=count+!st.empty();
            st.push(heights[i]);
            count=0;
        }
        return ans;
    }
};