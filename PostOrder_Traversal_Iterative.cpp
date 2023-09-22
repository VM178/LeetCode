class Solution {
public:
    void post(TreeNode* node,vector<int>&v){
        stack<TreeNode*> s;
        TreeNode* c = node;

        while(c || !s.empty()){
            if(c != NULL){
                s.push(c);
                c = c->left;
            }
            else{
                TreeNode *t = s.top()->right;
                if(t == NULL){
                    t = s.top();
                    s.pop();
                    v.push_back(t->val);
                    while(!s.empty() && t == s.top()->right){
                        t = s.top();
                        s.pop();
                        v.push_back(t->val);
                    }
                }
                else{
                    c = t;
                }
            }
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        post(root,v);
        return v;
    }
};