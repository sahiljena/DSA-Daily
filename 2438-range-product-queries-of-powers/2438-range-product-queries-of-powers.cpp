class Solution {
public:
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powRange;
        int k = 0;
        while(n>0){
            if(n%2) powRange.push_back((n%2)*pow(2,k++));
            else k++;
            n/=2;
        }
        vector<int>ans;
        int mod=1e9+7;
        for(auto i: queries){
            long temp=1;
            for(int j=i[0];j<=i[1];j++){
                temp=((temp%mod)*(powRange[j]%mod))%mod;
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};