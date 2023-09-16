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
    map<int,int> imap;
    TreeNode* tree(vector<int> &preorder,int pstart,int pend,vector<int> &inorder,int istart,int iend){

        if(pstart > pend || istart > iend){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[pstart]);
        int inode = imap[node->val];
        int numleft = inode - istart;

        node->left = tree(preorder,pstart+1,pstart+numleft,inorder,istart,inode-1);
        node->right = tree(preorder,pstart+numleft+1,pend,inorder,inode+1,iend);

        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        

        for(int i = 0;i < inorder.size();i++){
            imap[inorder[i]] = i;
        }
        TreeNode* root = tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return root;
    }
};