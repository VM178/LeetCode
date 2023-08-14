class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root == NULL){
            return ans;
        }
        q.push(root);
        int f = 1;
        while(!q.empty()){
            
            int s = q.size();
            vector<int> l(s);
            for(int i = 0;i < s;i++){
                TreeNode* n = q.front();
                q.pop();
                if(n->left != NULL){
                    q.push(n->left);
                }
                if(n->right != NULL){
                    q.push(n->right);
                }
                int j = f?i:s-i-1;
                l[j] = n->val;
            }
            f = !f;
            ans.push_back(l);
        }
        return ans;
    }
};