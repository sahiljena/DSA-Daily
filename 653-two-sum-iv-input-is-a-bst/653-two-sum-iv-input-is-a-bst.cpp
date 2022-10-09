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
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            arr.push_back(temp->val);
            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }
        map<int,int> mp;
        for(int i:arr) mp[i]=2;
        for(int i:arr){
            if(mp[k-i]==2 && k-i!=i) return true;
        }
        return false;
    }
};