class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        int l= words.size();
        int k= words[0].length();
        
        if(s.length()<l*k){
            return {};
        }
        
        unordered_map<string,int> mp;
        unordered_map<char,int> wmp;
        
        for(auto &it: words){
            mp[it]++;
            wmp[it[0]]++;
        }
        
        for(int i=0;i<=s.size()-l*k;i++){
            if(wmp[s[i]]==0){
                continue;
            }
            unordered_map<string,int> t(mp);
            bool flag=true;
            for(int j=0;j<l;j++){
                string temp= s.substr(i+j*k,k);
                if(t[temp]==0){
                    flag=false;
                    break;
                }
                t[temp]--;
            }
            if(flag){
            for(auto &it: t){
                if(it.second!=0){
                    flag=false;
                    break;
                }
            }
            }
            if(flag){
                v.push_back(i);
            }
        }
        
        return v;
    }
};