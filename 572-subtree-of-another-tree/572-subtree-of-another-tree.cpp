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
    // TreeNode* find(TreeNode* root, TreeNode* subRoot){
    //     if(!root) return nullptr;
    //     else if(root->val==subRoot->val){
    //         return root;
    //     }
    //     TreeNode* l = find(root->left,subRoot);
    //     TreeNode* r =  find(root->right,subRoot);
    //     return l? l:r;
    // }
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL && root == NULL) return true;
        if (subRoot == NULL || root == NULL) return false;
        if (root->val != subRoot->val) return false;
        return helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;
        bool res = helper(root, subRoot);
        if (res) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};