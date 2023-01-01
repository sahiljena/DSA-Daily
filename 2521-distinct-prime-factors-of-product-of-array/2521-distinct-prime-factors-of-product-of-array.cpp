class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int>s;
        
        for(int i:nums){
            int c = 2;
            while(i>1){
                if(i%c==0){
                    s.insert(c);
                    i/=c;
                }else ++c;
            }
        }
        return s.size();
    }
};