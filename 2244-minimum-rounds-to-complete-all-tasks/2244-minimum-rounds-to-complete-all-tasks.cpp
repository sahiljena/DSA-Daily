class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        for(int i:tasks) mp[i]++;
        
        int ans = 0;
        
        for(auto i:mp){
            if(i.second<2) return -1;
            if(i.second==2 || i.second==3) ++ans;
            else{
                int temp = i.second;
                int tc = 0;
                while(temp>0){ 
                    temp-=3;
                    ++tc;
                }
                if(temp==0 || temp==-1 || temp==-2) ans+=tc;
                else return -1;
            }
        }
        return ans;
    }
};