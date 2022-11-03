class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string,int>mp;
        int cnt=0;
        for(auto word:words){
            string temp=word;
            reverse(temp.begin(), temp.end());
            if(mp.find(temp)!=mp.end()){
                cnt+=4;
                if(mp[temp]==1) mp.erase(temp);
                else mp[temp]--;
            }else{
                mp[word]++;
            }
        }
        
        for(auto i:mp){
            if(i.first[0]==i.first[1]){
                cnt+=2;
                return cnt;
            }
        }
        return cnt;
    }
};