class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> m; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int lev = it.second; 
            if(m.find(lev) == m.end()){ 
		m[lev] = node->data; 
	    }
            
            if(node->left != NULL) {
                q.push({node->left,lev-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right,lev+1}); 
            }
            
        }
        
        for(auto it : m) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

};