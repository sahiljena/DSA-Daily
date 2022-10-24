class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int a1 = stoi(event1[0].substr(0,2)+event1[0].substr(3,2));
        int a2 = stoi(event1[1].substr(0,2)+event1[1].substr(3,2));
        int b1 = stoi(event2[0].substr(0,2)+event2[0].substr(3,2));
        int b2 = stoi(event2[1].substr(0,2)+event2[1].substr(3,2));
        

        if(a1<b1){
            if(a2<b1) return false;
        }
        if(a1>b1){
            if(b2<a1) return false;
        }
        return true;
    }
};