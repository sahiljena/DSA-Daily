class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int sum = skill[0]+skill[skill.size()-1];
        int i=1, j=skill.size()-2;
        long long ans = skill[0]*skill[skill.size()-1];
        // for(int i:skill) cout<<i<<" ";
        // cout<<endl;
        while(i<=j){
            // cout<<i<<" "<<j<<endl;
            if(skill[i]+skill[j]!=sum) return -1;
            else{
                ans+=(skill[i]*skill[j]);
                i++;
                j--;
            }
        }
        
        return ans;
    }
};