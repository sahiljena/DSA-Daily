class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        map<string,bool> mp;
        for(string word:words){
            
            if(word.size()>s.size())
                continue;
            else{
                if(mp.find(word)!=mp.end()){
                    if(mp[word]==true) ++ans;
                    continue;
                }
            
                int m = word.length();
                int i=0;
                int j=0;

                while(i<s.length() && j<word.length()){
                    if(s[i]==word[j]){
                        i++;
                        j++;
                    }else{
                        i++;
                    }
                }
                if(j==word.length()){ 
                    ++ans;
                    mp[word]=true;
                }
                else mp[word]=false;
                }
        }
        
        return ans;
    }
};