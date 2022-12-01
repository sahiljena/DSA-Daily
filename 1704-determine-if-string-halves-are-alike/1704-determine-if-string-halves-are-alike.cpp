class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int cnt=0;
        for(int i=0;i<n/2;i++){
            char c = tolower(s[i]);
            if(c=='a' || c=='e'|| c=='i'|| c=='o' || c=='u') cnt++;
        }
        for(int i=n/2;i<n;i++){
            char c = tolower(s[i]);
            if(c=='a' || c=='e'|| c=='i'|| c=='o' || c=='u') cnt--;
        }
        //cout<<cnt<<endl;
        return cnt==0;
    }
};