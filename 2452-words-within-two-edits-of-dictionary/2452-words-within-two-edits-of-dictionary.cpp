class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string w1:queries){
            int n = w1.length();
            for(string w2: dictionary){
                int m = w2.length();
                if(n==m){
                    int diff=0;
                    int l=0;
                    while(l<m){
                        if(w1[l]!=w2[l]) ++diff;
                        l++;
                    }
                    if(diff<=2){
                        ans.push_back(w1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};