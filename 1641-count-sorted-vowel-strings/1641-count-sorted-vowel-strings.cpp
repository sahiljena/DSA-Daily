class Solution {
public:
    int helper(int i, int n, vector<char>&vow){
        if(n==0) return 1;
        if(i==5) return 0;
        
        int pick = 0;
        if(n>0) pick = helper(i,n-1,vow);
        int notPick = helper(i+1,n,vow);
        
        return pick+notPick;
    }
    int countVowelStrings(int n) {
        vector<char> vovwelMap = {'a','e','i','o','u'};
        return helper(0,n,vovwelMap);
    }
};