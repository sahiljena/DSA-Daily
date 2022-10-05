class Solution {
public:
    bool helper(int n, int curr, int target){
        if(curr==n) return true;
        if(curr>n) return false;
        for(int i=target;i<16;i++){
            curr+=pow(3,i);
            if(helper(n,curr,i+1)) return true;
            curr-=pow(3,i);
        }
        return false;
    }
    bool checkPowersOfThree(int n) {
        return helper(n,0,0);
    }
};