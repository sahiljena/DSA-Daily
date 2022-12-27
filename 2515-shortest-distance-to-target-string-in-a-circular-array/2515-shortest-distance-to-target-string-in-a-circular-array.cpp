class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int t = n-1;
        int ans = INT_MAX;
        int i = startIndex;
        int count = 0;
        while(t--){
            count++;
            if(words[(i)%n]==target){
                ans = count-1;
                break;
            }
            i++;
        }
        t=n-1;
        i=startIndex;
        count=0;
        while(t--){
            count++;
            if(words[(i+n)%n]==target){
                ans = min(ans, count-1);
                break;
            }
            i--;
        }
        return ans==INT_MAX?-1:ans;
    }
};