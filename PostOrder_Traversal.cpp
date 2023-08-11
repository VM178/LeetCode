class Solution {
public:
    void post(TreeNode* node,vector<int>&v){
        if(node==NULL){
            return;
        }
        post(node->left,v);
        post(node->right,v);
        v.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        post(root,v);
        return v;
    }
};