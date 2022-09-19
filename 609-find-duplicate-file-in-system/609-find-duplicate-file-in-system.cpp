class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        map<string,vector<string>> mp;
        
        vector<vector<string>> ans;
        
        for(string str:paths){
            
            string dir;
            string fileName;
            string temp;
            string content;
            map<string,string> fileContentMap;
            for(char c:str){
                if(isspace(c) && !dir.length()){
                    dir=temp;
                    temp="";
                }
                if(c=='('){
                    fileName=temp;
                    // cout<<fileName<<" ";
                    temp="";
                }
                else if(c==')'){
                    content=temp;
                    if(fileName.length()) fileContentMap[fileName]=content;
                    temp="";
                    // cout<<"-> C : "<<content<<" ";
                }
                else{
                    temp+=c;
                }
            }
            for(auto i:fileContentMap){
                //cout<<i.first.substr(1)<<" "<<i.second<<endl;
                mp[i.second].push_back(dir+'/'+i.first.substr(1));
            }
        }
        
        for(auto i:mp){
            // cout<<i.first<<" ";
            // vector<string> temp;
            // for(auto j:i.second){
            //     temp.push_back(j);
            // }
            
            if(i.second.size()>1) ans.push_back(i.second);
        }
        return ans;
    }
};