class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        int k = 1;
        if(n==1)
            return "1";
        
        for(int u=0;u<n-1;u++){
            
            int k=0,i=1;
            int nl = ans.length();
            string tempans = "";
            int count = 1;
            while(k<nl){
                
                if(ans[k] == ans[i]){
                    count++;
                    i++;
                }else{
                    tempans += (to_string(count)+ans[k]);
                    k=i;
                    count = 1;
                    i = k+1;
                }
                
            }
            ans = tempans;
            
        }
        return ans;
    }
};