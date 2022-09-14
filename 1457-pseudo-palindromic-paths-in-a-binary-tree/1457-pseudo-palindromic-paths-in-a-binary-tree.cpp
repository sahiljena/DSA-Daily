/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void paths(TreeNode* root,vector<int>mp){
        if(!root) return;
        mp[root->val]++;
        if(!root->left && !root->right){
            int oddCnt=0;
            for(auto i:mp){
                if(i%2) oddCnt++;
            }
            if(oddCnt<=1) ++ans;
            return;
        }
        paths(root->left,mp);
        paths(root->right,mp);

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> mp(10, 0);
        paths(root,mp);
        return ans;
    }
};