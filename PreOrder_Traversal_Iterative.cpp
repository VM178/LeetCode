class Solution {
public:
    
    void pre(TreeNode* node,vector<int> &v){
        if(node == NULL){
            return ;
        }
        stack<TreeNode*> s;
        s.push(node);
        while(!s.empty()){
            TreeNode* t = s.top();
            s.pop();
            v.push_back(t->val);
            if(t->right){
                s.push(t->right);
            }
            if(t->left){
                s.push(t->left);
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        pre(root,v);
        return v;
    }
};