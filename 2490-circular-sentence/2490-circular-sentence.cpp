class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream s(sentence);
        string word;
        vector<string>strList;
        while (s >> word) strList.push_back(word);
        
        
        for(int i=0;i<strList.size();i++){
            string curr = strList[i];
            string next;
            if(i==strList.size()-1){
                next=strList[0];
            }else next = strList[i+1];

            if(curr[curr.length()-1]!=next[0]) return false;
        }
        return true;
    }
};