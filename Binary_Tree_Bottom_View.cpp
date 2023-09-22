class Solution
{
    public:
    vector<int> topView(TreeNode *root)
    {
        vector<int> ans; 
        if(root == NULL){ 
		return ans; 
	}	
        map<int,int> m; 
        queue<pair<TreeNode*, int>> q; 
        q.push({root,0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            TreeNode* node = it.first; 
            int lev = it.second; 
	    m[lev] = node->val; 
            if(node->left){
                q.push({node->left,lev-1}); 
            }
            if(node->right){
                q.push({node->right,lev+1}); 
            }
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

};