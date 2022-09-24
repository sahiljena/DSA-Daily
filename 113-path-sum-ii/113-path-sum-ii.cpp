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
    vector<int> path;
    vector<vector<int>>paths;
    void helper(TreeNode* root, int target, int currSum){
        if(!root) return;
        currSum+=root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && currSum==target){
            paths.push_back(path);
        }else{
            helper(root->left,target,currSum);
            helper(root->right,target,currSum);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        helper(root,target,0);
        return paths;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
};