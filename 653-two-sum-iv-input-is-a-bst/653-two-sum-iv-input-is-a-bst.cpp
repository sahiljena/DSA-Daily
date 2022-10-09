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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st;
        vector<int> arr;
        TreeNode* curr = root;
        while(curr!=NULL || !st.empty()){
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            arr.push_back(curr->val);
            curr=curr->right;
        }
        int low=0, high=arr.size()-1;
        while(low<high){
            int sum = arr[low]+arr[high];
            if(sum==k) return true;
            else if(sum<k) low++;
            else high--;
        }
        return false;
    }
};