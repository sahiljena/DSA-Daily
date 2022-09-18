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
    void helper(TreeNode* rootL, TreeNode* rootR,  int level){
        if(rootL==NULL && rootR==NULL) return;
        if(level%2==0) swap(rootR->val,rootL->val);
        
        helper(rootL->left,rootR->right,level+1);
        helper(rootL->right,rootR->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left,root->right, 0);
        return root;
    }
};