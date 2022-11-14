class Solution {
public:
    int reverse(int x) {
        int og=x;        
        x=abs(x);
        if(x%10==0)
            x=x/10;
        long long int res=0;
        while(x)
        {
            long long int r=x%10;
            x=x/10;
            res=res*10+r;
        }
        if(og<0)
            res=res*-1;
        if(res<=pow(2,31)-1 && res>=pow(-2,31))
        return res;
        return 0;
    }
};