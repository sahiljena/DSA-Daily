class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        map<string,vector<string>> mp;
        
        vector<vector<string>> ans;
        
        for(string str:paths){
            
            string dir;
            string fileName;
            string temp;
            // string content;
            map<string,string> fileContentMap;
            for(char c:str){
                if(isspace(c) && !dir.length()){
                    dir=temp;
                    temp="";
                }
                if(c=='('){
                    fileName=temp;
                    temp="";
                }
                else if(c==')'){
                    //content=temp;
                    if(fileName.length()) fileContentMap[fileName]=temp;
                    temp="";
                }
                else{
                    temp+=c;
                }
            }
            for(auto i:fileContentMap){
                mp[i.second].push_back(dir+'/'+i.first.substr(1));
            }
        }
        
        for(auto i:mp){
            if(i.second.size()>1) ans.push_back(i.second);
        }
        return ans;
    }
};