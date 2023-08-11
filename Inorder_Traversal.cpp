class Solution {
public:
    vector<int> v;
    void Inorder(TreeNode* node)
    {
        if (node == NULL){
            return;
        }
        Inorder(node->left);
        v.push_back(node->val);
        Inorder(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        Inorder(root);
        return v;
    }
};