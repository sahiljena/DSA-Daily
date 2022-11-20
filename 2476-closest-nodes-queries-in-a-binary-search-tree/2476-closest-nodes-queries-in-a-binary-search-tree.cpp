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
    
    void helper(TreeNode* root, vector<int>&treeArr){
        if(!root) return;
        helper(root->left, treeArr);
        treeArr.push_back(root->val);
        helper(root->right, treeArr);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> treeArr;
        helper(root,treeArr);
        vector<vector<int>> ans;
        for(int i:queries){
            int minDiff=INT_MAX;
            int maxDiff=INT_MAX;
            int minElem=-1, maxElem=-1;
            int low=0, high=treeArr.size()-1;
            int flag=-1;
            while(low<=high){
                int mid = low + ((high - low) / 2);
                if(treeArr[mid]==i){
                    ans.push_back({i,i});
                    flag=1;
                    break;
                }
                else if(treeArr[mid]>i){
                    if(treeArr[mid]-i<maxDiff){
                        maxDiff=treeArr[mid]-i;
                        maxElem=treeArr[mid];
                    }
                    high=mid-1;
                }else{
                    if(i-treeArr[mid]<minDiff){
                        minDiff=i-treeArr[mid];
                        minElem=treeArr[mid];
                    }
                    low=mid+1;
                }
            }
            if(flag==-1) ans.push_back({minElem, maxElem});
            
        }
        return ans;
    }
};