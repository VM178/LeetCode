class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root == NULL){
            return ans;
        }
        q.push(root);

        while(!q.empty()){
            vector<int> l;
            int s = q.size();
            for(int i = 0;i < s;i++){
                TreeNode* n = q.front();
                q.pop();
                if(n->left != NULL){
                    q.push(n->left);
                }
                if(n->right != NULL){
                    q.push(n->right);
                }
                l.push_back(n->val);
            }
            ans.push_back(l);
        }
        return ans;
    }
};