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
    void helper(TreeNode* root,TreeNode* &c){
        if(root == NULL){
            return;
        }
        helper(root->right,c);
        helper(root->left,c);
        root->right = c;
        root->left = NULL;
        c = root;
    } 
    void flatten(TreeNode* root) {
        TreeNode* c = NULL;
        helper(root,c);        
    }
};