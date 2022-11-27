class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        int piv=-1;
        int sum=0;
        for(int i=1;i<n+1;i++){
            sum+=i;
            int temp=0;
            if(sum>i){
                for(int j=i;j<n+1;j++){
                    temp+=j;
                    if(temp>sum) break;
                }
            }
            if(temp==sum){
                piv=i;
                break;
            }
        }
        return piv;
    }
};