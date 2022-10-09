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
        for(int i:arr) cout<<i<<" ";
        map<int,int> mp;
        for(int i:arr) mp[i]=2;
        for(int i:arr){
            if(mp[k-i]==2 && k-i!=i) return true;
        }
        return false;
    }
};