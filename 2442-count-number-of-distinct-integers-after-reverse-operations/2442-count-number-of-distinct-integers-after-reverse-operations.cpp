class Solution {
public:
    int pal(int a){
        int n=a;
        int rev = 0, rem;
        while (a != 0) {
            rem = a % 10;
            rev = rev * 10 + rem;
            a /= 10;
        }
        // cout<<n<<" "<<rev<<endl;
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int>s;
        for(int i:nums){
            s.insert(i);
            s.insert(pal(i));
        }
        return s.size();
    }
};