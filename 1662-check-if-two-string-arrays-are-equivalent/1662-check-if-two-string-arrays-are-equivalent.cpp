class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string t1, t2;
        for(auto i:word1) t1+=i;
        for(auto i:word2) t2+=i;
        // sort(t1.begin(), t1.end());
        // sort(t2.begin(), t2.end());
        return t1==t2;
    }
};