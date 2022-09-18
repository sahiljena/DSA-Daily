struct TrieNode {
    TrieNode *next[26] = {};
    int val = 0;
};

class Solution {
    TrieNode root;
public:
    
    void insert(string word){
        auto node = &root;
        for(char c:word){
            if(!node->next[c-'a']){
                node->next[c-'a'] = new TrieNode();
            }
            node->next[c-'a']->val++;
            node = node->next[c-'a'];
        }
    }
    
    int prefixCount(string s){
        int cnt=0;
        auto node = &root;
        for(char c:s){
            cnt+=node->next[c-'a']->val;
            node=node->next[c-'a'];
        }
        return cnt;
    }
    
    
    
    vector<int> sumPrefixScores(vector<string>& words) {
        
        
        int n = words.size();
        
        for(string word:words) insert(word);
        
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=prefixCount(words[i]);
        }
        return ans;
    }
};