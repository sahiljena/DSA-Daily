class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        
        priority_queue<int> pq;
        
        for(int i:nums) pq.push(i);
        
        while(!pq.empty() && k--){
            int num = pq.top();
            pq.pop();
            ans+=num;
            num = ceil((double)(num/3.0));
            pq.push(num);
        }
        
        return ans;
    }
};