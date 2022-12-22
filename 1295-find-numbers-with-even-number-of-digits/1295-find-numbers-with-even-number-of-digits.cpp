class Solution {
public:
    int digitLength(int num){
        int c = 0;
        while(num){
            ++c;
            num=num/10;
        }
        return c;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i: nums){
            if(digitLength(i)%2==0) ++ans;
        }
        return ans;
    }
};