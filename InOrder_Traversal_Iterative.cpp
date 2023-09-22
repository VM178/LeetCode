class Solution {
public:
    vector<int> v;
    void Inorder(TreeNode* node)
    {
        stack<TreeNode*> s;
        TreeNode* c = node;
        while(!s.empty() || c != NULL){
            while(c){
                s.push(c);
                c = c->left;
            }
            c = s.top();
            s.pop();
            v.push_back(c->val);
            c = c->right;

        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        Inorder(root);
        return v;
    }
};