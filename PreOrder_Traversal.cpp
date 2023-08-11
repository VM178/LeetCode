class Solution {
public:
    
    void pre(TreeNode* node,vector<int> &v){
        if(node == NULL){
            return;
        }
        v.push_back(node->val);
        pre(node->left,v);
        pre(node->right,v);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        pre(root,v);
        return v;
    }
};