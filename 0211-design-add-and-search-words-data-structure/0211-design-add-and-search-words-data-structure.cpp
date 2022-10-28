class WordDictionary {
public:
    struct Trie{
        Trie* leaves[26];
        bool isEOD=false;
    };
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* curr = root;
        for(char ch:word){
            if(!curr->leaves[ch-'a'])
                curr->leaves[ch-'a'] = new Trie();
            curr=curr->leaves[ch-'a'];
        }
        curr->isEOD=true;
    }
    
    bool search(string word) {
        Trie* curr = root;
        return dfs(word,0,curr);
    }
    
    bool dfs(string& word, int pos, Trie* node){
        for(pos;word[pos]&&node;pos++){
            if(word[pos]!='.'){
                node=node->leaves[word[pos]-'a'];
            }else{
                Trie* curr = node;
                for(int k=0;k<26;k++){
                    node=curr->leaves[k];
                    if(dfs(word,pos+1,node)) return true;
                }
            }
        }
        return node&&node->isEOD;
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */